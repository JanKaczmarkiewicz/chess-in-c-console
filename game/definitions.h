

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

const short BOARD_SIZE = 8;
const short MAX_MOVES_NUMBER = 7 * 4;

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
    UP_RIGHT,
    UP_LEFT,
    DOWN_LEFT,
    DOWN_RIGHT,
};

struct Coordinates {
    short x;
    short y;
};

#endif //DEFINITIONS_H
