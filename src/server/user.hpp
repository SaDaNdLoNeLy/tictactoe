/**
 * @file user.hpp
 * @author your name (you@domain.com)
 * @brief It contains the User class that stores the logged-in user.
 * @brief It also defines global data structures in which logged-in users 
 *        can be stored by name and socket.
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USER_HPP
#define USER_HPP

#include <string.h>
#include <map>
#include <vector>
#include <pthread.h>
#include "../global_message.hpp"

#define MAX_USERNAME_LEN 20
#define MAX_PASS_LEN 10
#define MIN_PASS_LEN 5

// Active User class
struct User
{
    std::string username;
    int sockfd;
    pthread_mutex_t mutex;

    User(std::string username, int sockfd = -1);
    ~User();

    void send(Message*);
};

// Store {sockfd, user} pair
extern std::map<int, User*> sockfd_user;
extern pthread_mutex_t sockfd_user_mutex;

// Store {username, user} pair
extern std::map<std::string, User*> username_user;
extern pthread_mutex_t username_user_mutex;

#endif