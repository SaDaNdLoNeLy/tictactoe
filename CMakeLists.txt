cmake_minimum_required(VERSION 3.20)

project(TicTacToe LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(tictactoe Main.cpp)
target_link_libraries(tictactoe ${SDL2_LIBRARIES})