#include <iostream>
#include <syslog.h>

#include "auth.hpp"

int main(){
    std::cout << "Hello World" << std::endl;
    char name[20], pass[20];
    user_db.open_db();
    user_db.create_user("hung81003", "081002");
    // FILE *f = fopen("user.txt", "r");
    // printf("%p\n", f);
    // while (fscanf(f, "%s %s", name, pass) != EOF){
    //     printf("Read\n");
    // };
    // fclose(f);
    
    
    
}