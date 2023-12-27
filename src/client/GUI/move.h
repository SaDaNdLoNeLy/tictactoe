#ifndef MOVE_H
#define MOVE_H

struct Move{
    Move(){}
    Move(int bRow, int bCol, int cRow, int cCol){
        this->bRow = bRow;
        this->bCol = bCol;
        this->cRow = cRow;
        this->cCol = cCol;
    }

    int bRow; // The row of valid board - board row
    int bCol; // The column of valid board - board col
    int cRow; // The row of move in valid board - cell row
    int cCol; // The column of move in valid board - cell col
};

#endif // MOVE_H
