cmake_minimum_required(VERSION 3.20)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)


file(GLOB_RECURSE serv_sources "src/server/*.cpp")
add_executable(server ${serv_sources})
target_include_directories(server PRIVATE src)

file(GLOB_RECURSE client_sources "src/client/*.cpp")
add_executable(client ${client_sources})
target_include_directories(client PRIVATE src)