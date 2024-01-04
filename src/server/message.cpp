/**
 * @file message.cpp
 * @author your name (you@domain.com)
 * @brief Server-side message handling
 * @version 0.1
 * @date 2024-01-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdlib.h>
#include <vector>
#include <pthread.h>
#include <unistd.h>

#include "server.hpp"
#include "../global_message.hpp"
#include "auth.hpp"
#include "user.hpp"

// process the registration message, the user is not yet authenticated here,
// therefore the responses must be written directly to the socket, they cannot be addressed to the user
// TODO: when responding on a direct socket, concurrency is not handled, there are several message processors
// thread, there is a race condition in the socket
void RegisterMessage::process(){
    if(username.length() == 0 || username.length() > MAX_USERNAME_LEN || pass.length() > MAX_PASS_LEN){
        ErrorMessage err("Invalid name or password length.");
        std::string msg = err.to_string();
        
        if(sockfd > 0) write(sockfd, msg.c_str(), msg.size());
        return;
    }

    // the new user is created in the database
    if(user_db.create_user(username, pass) < 0){
        ErrorMessage err("Username is already in use.");
        std::string msg = err.to_string();
        if(sockfd > 0) write(sockfd, msg.c_str(), msg.size());
    } else {
        OKMessage ok;
        std::string msg = ok.to_string();
        if(sockfd > 0) write(sockfd, msg.c_str(), msg.size());
    }
}    

// Handling the user's login message
void LoginMessage::process(){
    if(username.length() == 0 || username.length() > MAX_USERNAME_LEN || pass.length() > MAX_PASS_LEN){
        ErrorMessage err("Invalid name or pwd length.");
        std::string msg = err.to_string();
        if(sockfd > 0) write(sockfd, msg.c_str(), msg.size());
        return;
    }

    // we look for it in the database, if it doesn't exist, it's an error
    User *user = user_db.auth_user(username, pass);
    if(user == NULL){
        ErrorMessage err("Invalid name or pwd.");
        std::string msg = err.to_string();
        if(sockfd > 0) write(sockfd, msg.c_str(), msg.size());
        return;
    }

    pthread_mutex_lock(&sockfd_user_mutex);

    // if a socket was already assigned to the user, it must be deleted
    if(user->sockfd > 0) sockfd_user.erase(user->sockfd);
    user->sockfd = sockfd;

    // if another user is logged in with the same socket, it must be logged out
    User *other_user = sockfd_user[sockfd];
    if(other_user != NULL) other_user->sockfd = -1;

    // we set the new user for this socket
    sockfd_user[sockfd] = user;

    pthread_mutex_unlock(&sockfd_user_mutex);

    out_msg.push(new OKMessage((void*)user));
    printf("User logged in: %s\n", user->username.c_str());
}    

// new game initiation message
void StartMessage::process(){
    // pthread_mutex_lock(&sockfd_users_mutex);
    // User *u = sockfd_users[sockfd];    
    // pthread_mutex_unlock(&sockfd_users_mutex);

    // // if you are not logged in, we will return an error on the socket
    // if(u == NULL){
    //     ErrorMessage err("User hasn't logged in yet.");
    //     std::string msg = err.to_string();
    //     if(sockfd) write(sockfd, msg.c_str(), msg.size());
    //     return;
    // }
    
    // pthread_mutex_lock(&game_mutex);
    // Game *g = user_game[u];

    // // if a game already exists or you have already started one, an error is returned
    
    // if(g != NULL){
    //     pthread_mutex_unlock(&game_mutex);
    //     out_msg.push(new ErrorMessage("You are already in a game.", (void*) u));
    //     return;
    // }
    
    // if(u == queued_user){
    //     pthread_mutex_unlock(&game_mutex);
    //     out_msg.push(new ErrorMessage("You are already queued.", (void*) u));
    //     return;
    // }

    // // there is no one on the waiting list yet, so you will be added there
    // if(queued_user == NULL){
    //     queued_user = u;
    //     pthread_mutex_unlock(&game_mutex);
    //     syslog(LOG_INFO, "StartMessage: User %s queued.", u->name.c_str());
    //     out_msg.push(new OKMessage((void*) u));
        return;
    }

    // // here the game is created between u and queued_user
    // out_msg.push(new OKMessage((void*) u));

    // g = new Game(u, queued_user, GAME_LENGTH_ms);
    // user_game[u] = g;
    // user_game[queued_user] = g;

    // syslog(LOG_INFO, "Game starting: %s %s\n",u->name.c_str(), queued_user->name.c_str());
    // queued_user = NULL;    

    // pthread_mutex_unlock(&game_mutex);
    
    // g->start();


// the player's step message
void MoveMessage::process(){
    // pthread_mutex_lock(&sockfd_users_mutex);
    // User *user = sockfd_users[sockfd];
    // pthread_mutex_unlock(&sockfd_users_mutex);

    // if(user == NULL) return;

    // pthread_mutex_lock(&game_mutex);
    // Game *game = user_game[user];
    // pthread_mutex_unlock(&game_mutex);

    // if(game == NULL){
    //     out_msg.push(new ErrorMessage("no game running.", (void*) user));
    //     return;
    // }

    // game->move(user, from, to);
    return;
}


// this indicates that a connection has been lost on a socket
void DisconnectMessage::process(){
    pthread_mutex_lock(&sockfd_user_mutex);
    User* u = sockfd_user[sockfd];
    sockfd_user.erase(sockfd);
    pthread_mutex_unlock(&sockfd_user_mutex);

    // no one was logged in on the socket
    if(u == NULL){
        printf("client disconnected from socket %d\n", sockfd);
        return;
    }

    // if the user was waiting for a game, we take it out.
    // if it is in the game, it continues, you can still connect back
    // pthread_mutex_lock(&game_mutex);    
    // u->sockfd = -1;
    // if(queued_user == u) queued_user = NULL;
    // pthread_mutex_unlock(&game_mutex);

    printf("User disconnected: %s\n", u->username.c_str());
}

//// server -> client messages. They just need to be forwarded

void ErrorMessage::process(){
    User *u = (User*) user;
    
    if(u != NULL)
        u->send(this);
}

void OKMessage::process(){
    User *u = (User*) user;

    if(u != NULL)
        u->send(this);
}

// void GameMessage::process() {
//     // pthread_mutex_lock(&username_user_mutex);
//     // User *w = username_user[white];
//     // User *b = name_users[black];
//     // pthread_mutex_unlock(&username_user_mutex);

//     // if(b != NULL){
//     //     b->send(this);
//     // }

//     // if(w != NULL){
//     //     w->send(this);
//     // }
//     return;
// }

void MovedMessage::process(){
    User *u = (User*) user;

    if(u != NULL){
        u->send(this);
    }
}



Message* parseMessage(char *buf, int len, int sockfd) {
    std::vector<std::string> parts;
    int start = 0;
    for(int i = 0; i < len; i++){
        if(buf[i] == ' ' || buf[i] == '\n'){
            buf[i] = '\0';
            parts.push_back(std::string(buf + start));
            start = i + 1;
        }
    }

    if(parts.size() == 0) goto err;

    Message *m;

    if(parts[0] == "REGISTER"){
        if(parts.size() != 3) goto err;
        m = new RegisterMessage(parts[1], parts[2], sockfd);
    } else if(parts[0] == "LOGIN"){
        if(parts.size() != 3) goto err;
        m = new LoginMessage(parts[1], parts[2], sockfd);
    } else if(parts[0] == "START"){
        if(parts.size() > 1) goto err;
        m = new StartMessage(sockfd);
    } else if(parts[0] == "MOVE"){
        if(parts.size() != 2) goto err;
        
        int coord = string_to_int(parts[1]);
        if(coord < 0 || coord > 63) goto err;
        
        m = new MoveMessage(coord, sockfd);
    } else goto err; 
    
    return m;
    
err:
    printf("parseMessage: Invalid message format.\n");
    return NULL;
}

