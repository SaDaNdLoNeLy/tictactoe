#include <stdio.h>
#include <string.h>
#include "match.hpp"

Board::Board(){
    memset((void *)board, 0, sizeof(board));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = EMPTY;
        }
    }
}

void Board::move(int row, int col, int type){
    if ((row > 2 || row < 0) || (col > 2 || col < 0)){
        printf("Wrong move format.\n");
        return;
    }

    if (board[row][col] != EMPTY){
        printf("Not a empty cell.\n");
        return;
    }

    board[row][col] = type;
}