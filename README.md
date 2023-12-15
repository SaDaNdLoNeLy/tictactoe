# Client-server tictactoe application

## Description

This project aims to create a simple server-client application  
for the network programming course by making online ultimate tic-tac-toe

Functionalities of server:

- save registered user
- handle multiple concurrent game
- search for random opponents

Functionalities of client:

- communicate with client
- display GUI
- handle game-logic

## Tools

CMake, g++, SDL2

## Run
### For Linux system
Make sure you install **cmake**, **libsdl2-dev** and **g++**

To compile the project run this on terminal
```bash
mkdir build
cd build
cmake ../ #Must in build dir terminal
cmake --build ./
```

The execute file is in build folder

## Sample
- Initializer list
- Constructor/Destructor struct
- mutex/thread
- extern
- syslog
