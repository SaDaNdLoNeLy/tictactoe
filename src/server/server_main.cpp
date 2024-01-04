// #include <iostream>
// #include <syslog.h>

// #include "auth.hpp"

// int main(){
//     std::cout << "Hello World" << std::endl;
//     char name[20], pass[20];
//     user_db.open_db();

//     std::cout << "Hello World" << std::endl;
//     user_db.create_user("hung81005", "081002");
//     std::cout << "Hello World" << std::endl;
//     FILE *f = fopen(DB_PATH, "r+");
//     if (f == NULL)
//         printf("Sth went wrong\n");
//     printf("%p\n", f);
//     while (fscanf(f, "%s %s", name, pass) != EOF){
//         printf("Read\n");
//     };
//     fclose(f);
//     openlog("chess_srv", LOG_PID, LOG_LOCAL1);
    
    
// }

///
///  main.cpp
///  Starts the server.
///

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include "server.hpp"



int main(int argc, char* argv[]){

    // there can be a single argument, the port number
    if (argc > 2) {
        printf("Too many arguments, the only (optional) argument is the port number to run on.\n");
        return 2;
    }

    printf("Hello\n");

    const char *port = NULL;
    if (argc == 2) {
        port = argv[1];
        int port_number = atoi(port);
        if (strlen(port) > 6 || port_number <= 0 || port_number >= (1 << 16)){
            printf("Invalid port number provided.\n");
            return 3;
        }
    }
            

    // // runs as a daemon, it keeps the current directory because it creates the data file there
    // // keep the current working directory but close its standard file descriptors
    // if(daemon(1, 0) < 0){
    //     perror("daemon");
    //     return EXIT_FAILURE;
    // }
    printf("Hello\n");
    openlog("chess_srv", LOG_PID, LOG_DAEMON);
    printf("Hello\n");
    start_server(port);
    printf("Hello\n");
}
