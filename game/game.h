
#ifndef GAME_H
#define GAME_H

const short int BOARD_SIZE = 8;

enum ChessmanType {
    KING,
    QUEEN,
    PAWN,
    CASTLE,
    KNIGHT,
    BISHOP,
};


enum Side {
    WHITE,
    BLACK,
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};


struct Chessman {
    enum ChessmanType type;
    enum Side side;
};


struct Chessman cc(enum Side side, enum ChessmanType chessmanType) {
    struct Chessman chessman;
    chessman.side = side;
    chessman.type = chessmanType;
    return chessman;
}


#endif //HELLO_GAME_H
