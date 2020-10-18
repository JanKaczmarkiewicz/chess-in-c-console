#include <stdbool.h>
#include <stdlib.h>

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
    EMPTY,
};

enum Side {
    WHITE,
    BLACK,
    NONE,
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

struct Chessman cc(enum Side side, enum ChessmanType chessman_type) {
    struct Chessman chessman = {
            .side=side,
            .type=chessman_type,
    };
    return chessman;
}


struct State {
    enum Side current_turn;
    int selected_tile[2];
    struct Chessman board[BOARD_SIZE+1][BOARD_SIZE+1];
};

void select_tile(struct State *state, int x, int y) {
    if(&state->board[x][y].side != &state->current_turn) return;

    state->selected_tile[0] = x;
    state->selected_tile[1] = y;
}


#endif //GAME_H
