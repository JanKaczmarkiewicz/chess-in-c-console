#include "bishop.h"

const short BISHOP_DIRECTIONS_NUMBER = 4;
Direction BISHOP_DIRECTIONS[BISHOP_DIRECTIONS_NUMBER] = {UP_RIGHT, UP_LEFT, DOWN_LEFT, DOWN_RIGHT};

void assign_bishop_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                  short *current_index) {
    for (int i = 0; i < BISHOP_DIRECTIONS_NUMBER; ++i) {
        assign_direction_moves(state, coordinates, possible_moves, current_index, BISHOP_DIRECTIONS[i]);
    }
}
