#ifndef MATCH_HPP
#define MATCH_HPP

#include <vector>
#include <utility>

#define WHITE 1
#define BLACK 0

using std::pair;
using std::vector;

enum State {
    EMPTY = -1,
    X = 0,
    Y = 1,
};

struct Board
{
    int board[3][3];

    Board();

    void move(int row, int col, int type);
};


struct Match
{
    pair<int, int> last_move;
    Board board_list[3][3];
    
    Match();

    bool player_check(int board);
    
};


#endif