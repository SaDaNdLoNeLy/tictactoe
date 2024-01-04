/**
 * @file global_message.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-9-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <syslog.h>
#include <stdexcept>

#include "global_message.hpp"

Message::~Message() {}

MessageQueue::MessageQueue()
{
    pthread_cond_init(&empty, NULL);
    pthread_mutex_init(&mutex, NULL);
}

MessageQueue::~MessageQueue()
{
    pthread_cond_destroy(&empty);
    pthread_mutex_destroy(&mutex);
}

void MessageQueue::push(Message *m)
{
    pthread_mutex_lock(&mutex);
    // If the queue was empty before the push, signal that it's no longer empty
    if (queue.empty())
        pthread_cond_signal(&empty);
    queue.push(m);
    pthread_mutex_unlock(&mutex);
}

Message* MessageQueue::pop()
{
    pthread_mutex_lock(&mutex);
    // If the queue is empty, wait until it becomes non-empty
    if (queue.empty())
        pthread_cond_wait(&empty, &mutex);

    Message *m = queue.front();
    queue.pop();

    pthread_mutex_unlock(&mutex);
    return m;
}

void* MessageQueueWorker::work(void *data)
{
    MessageQueue *q = (MessageQueue *)data;
    while (true)
    {
        Message *m = q->pop();
        m->process();
        delete m;
    }
}

// to_string() function for cli - serv mess
std::string RegisterMessage::to_string()
{
    std::string s = "REGISTER " + username + " " + pass + "\n";
    return s;
}

std::string LoginMessage::to_string()
{
    std::string s = "LOGIN " + username + " " + pass + "\n";
    return s;
}

std::string StartMessage::to_string()
{
    std::string s = "START\n";
    return s;
}

std::string MoveMessage::to_string()
{
    std::string s = "MOVE " + std::to_string(coord) + "\n";
    return s;
}

// to_string() function for serv - cli mess
std::string OKMessage::to_string()
{
    return std::string("OK\n");
}

std::string ErrorMessage::to_string()
{
    std::string s = "ERROR " + err + "\n";
    return s;
}

std::string MovedMessage::to_string()
{
    std::string s = "MOVED " + std::to_string(coord) + "\n";
    return s;
}

std::string DisconnectMessage::to_string(){
    std::string s = "DISCONNECTED " + std::to_string(sockfd) + "\n";
    return s;
}

// Constructor

RegisterMessage::RegisterMessage(std::string username, std::string pass, int sockfd)
    : username(username), pass(pass), sockfd(sockfd) {}

LoginMessage::LoginMessage(std::string username, std::string pass, int sockfd)
    : username(username), pass(pass), sockfd(sockfd) {}

StartMessage::StartMessage(int sockfd)
    : sockfd(sockfd) {}

MoveMessage::MoveMessage(int coord, int sockfd)
    : coord(coord), sockfd(sockfd) {}

OKMessage::OKMessage(void *user)
    : user(user) {}

ErrorMessage::ErrorMessage(std::string err, void *user)
    : err(err), user(user) {}

MovedMessage::MovedMessage(int coord, void *user)
    : coord(coord), user(user) {}

DisconnectMessage::DisconnectMessage(int _sockfd)
    :sockfd(_sockfd) {}


// string to int
int string_to_int(std::string s)
{
    int res;
    try
    {
        res = std::stoi(s);
    }
    catch (std::invalid_argument const &e)
    {
        return -1;
    }

    return res;
}