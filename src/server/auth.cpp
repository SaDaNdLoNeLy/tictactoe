/**
 * @file auth.cpp
 * @author your name (you@domain.com)
 * @brief Implement of database class that store user data
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "user.hpp"
#include "auth.hpp"

DataEntry::DataEntry(std::string username, std::string pass)
    :username(username), pass(pass) {}

DataEntry::~DataEntry(){}

// Global db instance
UserDB user_db;

// Init rwlock instance for stopping concurent write
UserDB::UserDB(){
    if (pthread_rwlock_init(&rwlock, NULL)){
        syslog(LOG_ERR, "pthread_rwlock_init: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Destroy rwlock instance for stopping concurent write
UserDB::~UserDB(){
    if (pthread_rwlock_destroy(&rwlock)){
        syslog(LOG_ERR, "pthread_rwlock_destroy: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void UserDB::open_db(){
    // Open file with DB_PATH if not exit create new one
    int f = open(DB_PATH, O_CREAT, 0660);

    if (f < 0){
        syslog(LOG_ERR, "open_db(): %s", strerror(errno));
        printf("%s\n", strerror(errno));
    }

    close(f);
}

std::vector<DataEntry>* UserDB::read_db(){
    std::cout << "Hello World 1" << std::endl;
    std::vector<DataEntry>* db = new std::vector<DataEntry>();
    std::cout << "Hello World 2" << std::endl;
    // Wait wlock when other thread is write data
    pthread_rwlock_rdlock(&rwlock);

    std::cout << "Hello World 3" << std::endl;
    FILE* f = fopen(DB_PATH, "r+");
    if (f == NULL){
        syslog(LOG_ERR, "fopen(): %s", strerror(errno));
    }
    std::cout << "Hello World 4" << std::endl;
    char buffer_username[MAX_USERNAME_LEN+1], buffer_pass[MAX_PASS_LEN+1];

    while (fscanf(f, "%s %s", buffer_username, buffer_pass) != EOF){
        std::cout << "Hello World 6" << std::endl;
        db->push_back(DataEntry(buffer_username, buffer_pass));
    }
    std::cout << "Hello World 5" << std::endl;
    fclose(f);
    if (pthread_rwlock_unlock(&rwlock)){
        syslog(LOG_ERR, "UserDB::read_db() rwlock_unlock(): %s", strerror(errno));
    }

    return db;
}

// Auth user
User* UserDB::auth_user(std::string username, std::string pass){
    std::vector<DataEntry>* db = read_db();

    // NULL User by default
    User* user = NULL;

    for (int i = 0; i < db->size(); i++){
        // Successfull auth
        if ((*db)[i].username == username && (*db)[i].pass == pass){
            pthread_mutex_lock(&username_user_mutex);

            // Check if user is logged in or not, if yes return old user instance
            user = username_user[username];

            // Not logged in
            if (user == NULL){
                user = new User(username);
                username_user[username] = user;
            }

            pthread_mutex_unlock(&username_user_mutex);
            break;
        }
    }

    delete(db);
    return user;
}

int UserDB::create_user(std::string username, std::string pass){
    std::vector<DataEntry> *db = read_db();

    // Check name is taken ?
    for (int i = 0; i < db->size(); i++){
        if ((*db)[i].username == username){
            delete(db);
            return -1;
        }
    }
    delete(db);

    pthread_rwlock_wrlock(&rwlock);
    FILE *f = fopen(DB_PATH, "a");
    fprintf(f, "%s %s\n", username.c_str(), pass.c_str());
    fclose(f);
    pthread_rwlock_unlock(&rwlock);

    return 0;
}