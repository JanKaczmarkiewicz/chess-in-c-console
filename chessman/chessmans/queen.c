#include "queen.h"

const short QUEEN_DIRECTIONS_NUMBER = 8;
Direction QUEEN_DIRECTIONS[QUEEN_DIRECTIONS_NUMBER] = {UP, DOWN, LEFT, RIGHT, UP_RIGHT, UP_LEFT, DOWN_LEFT,
                                                            DOWN_RIGHT};
void assign_queen_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                 short *current_index) {
    for (int i = 0; i < QUEEN_DIRECTIONS_NUMBER; ++i) {
        assign_direction_moves(state, coordinates, possible_moves, current_index, QUEEN_DIRECTIONS[i]);
    }
}
