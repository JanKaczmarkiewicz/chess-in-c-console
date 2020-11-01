#include "../helpers/helpers.h"

#ifndef KNIGHT_H
#define KNIGHT_H

const short KNIGHT_MOVES_MODIFICATORS_NUMBER = 8;
struct Coordinates KNIGHT_MOVES_MODIFICATORS[KNIGHT_MOVES_MODIFICATORS_NUMBER] = {
        {-2, -1},
        {-2, 1},
        {-1, 2},
        {1,  2},
        {2,  1},
        {2,  -1},
        {1,  -2},
        {-1, -2},
};

struct Coordinates **
assign_knight_possible_moves(struct State *state, short x, short y, struct Coordinates **possible_moves,
                             short *current_index) {
    struct Chessman *knight = state->board[y][x];
    for (short i = 0; i < KNIGHT_MOVES_MODIFICATORS_NUMBER; i++) {

        struct Coordinates *current = create_coordinates(
                x + KNIGHT_MOVES_MODIFICATORS[i].x,
                y + KNIGHT_MOVES_MODIFICATORS[i].y
        );

        if (!is_possible_move(state, knight->side, current->x, current->y)) continue;

        possible_moves[*current_index] = current;
        *current_index += 1;
    }
    return possible_moves;
}

#endif //KNIGHT_H
