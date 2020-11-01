#ifndef BISHOP_H
#define BISHOP_H

#include "definitions.h"
#include "../helpers/helpers.h"

const short BISHOP_DIRECTIONS_NUMBER = 4;
enum Direction BISHOP_DIRECTIONS[BISHOP_DIRECTIONS_NUMBER] = {UP_RIGHT, UP_LEFT, DOWN_LEFT, DOWN_RIGHT};

void assign_bishop_possible_moves(struct State *state, short x, short y, struct Coordinates **possible_moves,
                                  short *current_index) {
    assign_directions_possible_moves(state, x, y, possible_moves, current_index, &BISHOP_DIRECTIONS,
                                     BISHOP_DIRECTIONS_NUMBER);
}

#endif //BISHOP_H
