

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

struct Chessman {
    enum ChessmanType type;
    enum Side side;
};

struct State {
    enum Side current_side;
    struct Coordinates *selected_tile;
    struct Chessman *board[BOARD_SIZE][BOARD_SIZE];
};

#endif //DEFINITIONS_H
