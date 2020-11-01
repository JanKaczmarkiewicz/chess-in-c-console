#include "../helpers/helpers.h"

#ifndef QUEEN_H
#define QUEEN_H

const short QUEEN_DIRECTIONS_NUMBER = 8;
enum Direction QUEEN_DIRECTIONS[QUEEN_DIRECTIONS_NUMBER] = {UP, DOWN, LEFT, RIGHT, UP_RIGHT, UP_LEFT, DOWN_LEFT,
                                                            DOWN_RIGHT};
void assign_queen_possible_moves(struct State *state, short x, short y, struct Coordinates **possible_moves,
                                 short *current_index) {
    assign_directions_possible_moves(state, x, y, possible_moves, current_index, &QUEEN_DIRECTIONS,
                                     QUEEN_DIRECTIONS_NUMBER);
}

#endif //QUEEN_H
