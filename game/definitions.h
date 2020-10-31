
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

const short QUEEN_DIRECTIONS_NUMBER = 8;
enum Direction QUEEN_DIRECTIONS[QUEEN_DIRECTIONS_NUMBER] = {UP, DOWN, LEFT, RIGHT, UP_RIGHT, UP_LEFT, DOWN_LEFT, DOWN_RIGHT};

const short CASTLE_DIRECTIONS_NUMBER = 4;
enum Direction CASTLE_DIRECTIONS[CASTLE_DIRECTIONS_NUMBER] = {UP, DOWN, LEFT, RIGHT};

const short BISHOP_DIRECTIONS_NUMBER=4;
enum Direction BISHOP_DIRECTIONS[BISHOP_DIRECTIONS_NUMBER] = {UP_RIGHT, UP_LEFT, DOWN_LEFT, DOWN_RIGHT};
#endif //DEFINITIONS_H
