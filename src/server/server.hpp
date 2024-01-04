/**
 * @file server.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "../global_message.hpp"

// Default PORT if no argument is provided
#define PORT "8000"

// timeout time of the poll() call in ms when managing clients
#define POLL_WAIT 500

extern MessageQueue in_msg, out_msg;

void start_server(const char*);

void* handle_client(void*);

#endif