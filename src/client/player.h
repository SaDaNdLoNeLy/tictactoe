#ifndef PLAYER_H
#define PLAYER_H

enum PieceType{
    PIECE_TYPE_NONE,
    PIECE_TYPE_X,
    PIECE_TYPE_O
};

class Player
{
public:
    Player();
    Player(int user_, PieceType type_);

    PieceType getPieceType() const;
    void setPlayerType(PieceType type_);

    void setUser(int user_);
    int getUser() const;

    friend bool operator==(const Player& lhs, const Player& rhs);

private:
    int user_;
    PieceType type_;
};

#endif // PLAYER_H
