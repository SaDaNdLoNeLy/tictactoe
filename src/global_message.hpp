/**
 * @file global_message.hpp
 * @author your name (you@domain.com)
 * @brief It contains the Message class and Message queue
 * @version 0.1
 * @date 2023-9-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <queue>
#include <vector>
#include <pthread.h>


struct Message
{
    // abstract func
    virtual std::string to_string() = 0;
    virtual void process() = 0;
    virtual ~Message();
};

Message* parseMessage(char *buf, int len, int sockfd);
int string_to_int(std::string s);

struct MessageQueue
{
    std::queue<Message*> queue;
    // Check if queue is empty
    pthread_cond_t empty;
    // Lock for exclusive access to the queue
    pthread_mutex_t mutex;

    // Constructor
    MessageQueue();
    // Destructor
    ~MessageQueue();

    void push(Message*);
    Message* pop();
};

struct MessageQueueWorker {
    static void* work(void *);
};

// Client - Server message
struct RegisterMessage : public Message
{
    std::string username, pass;
    int sockfd;

    RegisterMessage(std::string username, std::string pass, int sockfd = -1);

    std::string to_string();
    void process();
};

struct LoginMessage : public Message
{
    std::string username, pass;
    int sockfd;

    LoginMessage(std::string username, std::string pass, int sockfd = -1);

    std::string to_string();
    void process();
};

struct StartMessage : public Message
{
    int sockfd;

    StartMessage(int sockfd = -1);

    std::string to_string();
    void process();
};

struct MoveMessage : public Message
{
    int coord, sockfd;

    MoveMessage(int coord, int sockfd = -1);

    std::string to_string();
    void process();
};

struct OKMessage : public Message
{
    void *user;

    OKMessage(void* user = NULL);

    std::string to_string();
    void process();
};

struct ErrorMessage : public Message
{
    std::string err;
    void *user;

    ErrorMessage(std::string err, void* user = NULL);

    std::string to_string();
    void process();
};

struct MovedMessage : public Message
{
    int coord;
    void *user;

    MovedMessage(int coord, void* user = NULL);

    std::string to_string();
    void process();
};


#endif