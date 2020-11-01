#ifndef CASTLE_H
#define CASTLE_H

#include "definitions.h"
#include "../helpers/helpers.h"

const short CASTLE_DIRECTIONS_NUMBER = 4;
enum Direction CASTLE_DIRECTIONS[CASTLE_DIRECTIONS_NUMBER] = {UP, DOWN, LEFT, RIGHT};

void assign_castle_possible_moves(struct State *state, short x, short y, struct Coordinates **possible_moves,
                                  short *current_index) {
    assign_directions_possible_moves(state, x, y, possible_moves, current_index, &CASTLE_DIRECTIONS,
                                     CASTLE_DIRECTIONS_NUMBER);
}

#endif //CASTLE_H
