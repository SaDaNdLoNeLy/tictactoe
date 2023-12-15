#include <iostream>
#include <syslog.h>

#include "auth.hpp"

int main(){
    std::cout << "Hello World" << std::endl;
    user_db.open_db();
    user_db.read_db();
    user_db.create_user("hung81001", "081002");
}