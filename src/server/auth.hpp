/**
 * @file auth.hpp
 * @author your name (you@domain.com)
 * @brief Define for database
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef AUTH_HPP
#define AUTH_HPP

#include <pthread.h>
#include <string>
#include <vector>
#include "user.hpp"

#define DB_PATH "../src/server/user.txt"

struct DataEntry {
    std::string username, pass;

    DataEntry(std::string username, std::string pass);
    ~DataEntry();
};

// Handle file and read-write race of multiple thread
struct UserDB {
    // Block multiple thread write db file at same time
    pthread_rwlock_t rwlock;

    UserDB();
    ~UserDB();

    // Open file and read data to DB
    void open_db();
    // Return database instance from txt file
    std::vector<DataEntry>* read_db();
    
    User* auth_user(std::string username, std::string pass);
    int create_user(std::string username, std::string pass);
};

// ONLY 1 UserDB is created NO reinitialization because of multiple rwlock
extern UserDB user_db;

#endif