/**
 * @file user.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <syslog.h>
#include <unistd.h>

#include "user.hpp"
#include "../global_message.hpp"

std::map<int, User*> sockfd_user;
pthread_mutex_t sockfd_user_mutex = PTHREAD_MUTEX_INITIALIZER;

std::map<std::string, User*> username_user;
pthread_mutex_t username_user_mutex = PTHREAD_MUTEX_INITIALIZER;

// Constructor initializer
User::User(std::string username, int sockfd)
    :username(username), sockfd(sockfd) {};

// Destructor initializer
User::~User(){
    pthread_mutex_destroy(&mutex);
}

// Send message to User
void User::send(Message* m){
    if (sockfd <= 0) return;
    std::string s = m->to_string();

    pthread_mutex_lock(&mutex);
    ssize_t len = write(sockfd, s.c_str(), s.size());
    pthread_mutex_unlock(&mutex);

    // Failed to send entire message, error
    if(len != s.size())
        syslog(LOG_ERR, "User::send() cannot send message.");
}