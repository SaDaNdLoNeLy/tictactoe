/**
 * @file server.cpp
 * @author your name (you@domain.com)
 * @brief Implement server function
 * @version 0.1
 * @date 2023-12-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <vector>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <poll.h>

#include "server.hpp"
#include "auth.hpp"

MessageQueue in_msg, out_msg;
std::vector<pollfd> clients, new_clients;

// Prevent
pthread_mutex_t new_clients_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t new_clients_empty = PTHREAD_COND_INITIALIZER;

void start_server(const char *port = NULL)
{
    addrinfo hints;
    addrinfo *res, *res_saved;

    bzero(&hints, sizeof(hints));
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (port == NULL)
    {
        port = &PORT[0];
    }

    int err = getaddrinfo(NULL, port, &hints, &res);
    if (err != 0)
    {
        printf("getaddrinfo: %s\n", gai_strerror(err));
    }

    res_saved = res;
    int ssock = -1;
    while (res != NULL && ((ssock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0))
    {
        printf("socket: %s\n", strerror(errno));
        res = res->ai_next;
    }

    if (ssock < 0)
    {
        printf("socket: Cannot open socket.\n");
        exit(EXIT_FAILURE);
    }

    int reuse = 1;
    setsockopt(ssock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(ssock, res->ai_addr, res->ai_addrlen) < 0)
    {
        printf("listen: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (listen(ssock, 10) < 0)
    {
        printf("listen: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res_saved);
    printf("Server up.\n");

    pthread_t in, out;

    if (pthread_create(&in, NULL, MessageQueueWorker::work, (void *)&in_msg))
    {
        printf("pthread_create: %s\n", strerror(errno));
    }
    if (pthread_create(&out, NULL, MessageQueueWorker::work, (void *)&out_msg))
    {
        printf("pthread_create: %s\n", strerror(errno));
    }

    pthread_t client_handler;

    if (pthread_create(&client_handler, NULL, MessageQueueWorker::work, (void *)&in_msg))
    {
        printf("pthread_create: %s\n", strerror(errno));
    }

    user_db.open_db();

    sockaddr_in client_addr;
    int csock;
    socklen_t addr_len = sizeof(client_addr);

    while ((csock = accept(ssock, (sockaddr *)&client_addr, &addr_len)) >= 0)
    {
        printf("New client accepted, socket fd: %d\n", csock);
        pthread_mutex_lock(&new_clients_mutex);

        pollfd cpoll;

        memset(&cpoll, 0, sizeof(cpoll));
        cpoll.fd = csock;
        cpoll.events |= POLLIN;

        if (new_clients.size() == 0)
            pthread_cond_signal(&new_clients_empty);

        new_clients.push_back(cpoll);
        pthread_mutex_unlock(&new_clients_mutex);
    }

    printf("accept: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
}

void *handle_client(void *data)
{
    char buf[1024];

    while (1)
    {
        // Add new clients to clients poll fd
        pthread_mutex_lock(&new_clients_mutex);

        // if no clients and new clients are waiting => wait
        if (clients.size() == 0 && new_clients.size() == 0)
            pthread_cond_wait(&new_clients_empty, &new_clients_mutex);

        // add new clients
        for (int i = 0; i < new_clients.size(); i++)
            clients.push_back(new_clients[i]);

        new_clients.clear();
        pthread_mutex_unlock(&new_clients_mutex);

        if (poll(&clients[0], clients.size(), POLL_WAIT) < 0)
        {
            printf("poll: %s\n", strerror(errno));
        }

        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].revents & (POLLERR | POLLNVAL))
            {
                printf("poll: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            // FD ready to read
            if (clients[i].revents & POLLIN)
            {
                int read_len = read(clients[i].fd, buf, sizeof(buf));

                if (read_len == 0)
                {
                    in_msg.push(new DisconnectMessage(clients[i].fd));
                    clients[i].fd *= -1;
                }
                else if (read_len < 0)
                {
                    printf("read: %s\n", strerror(errno));
                    exit(EXIT_FAILURE);
                }
                else
                {
                    int start = 0;
                    for (int j = 0; j < read_len; j++)
                    {
                        if (buf[j] == '\n')
                        {
                            Message *msg = parseMessage(buf + start, j - start + 1, clients[i].fd);
                            if (msg != NULL)
                            {
                                in_msg.push(msg);
                            }
                            start = j + 1;
                        }
                    }
                }
            }
        }
    }
}