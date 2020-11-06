#include "castle.h"

const short CASTLE_DIRECTIONS_NUMBER = 4;
Direction CASTLE_DIRECTIONS[CASTLE_DIRECTIONS_NUMBER] = {UP, DOWN, LEFT, RIGHT};

void assign_castle_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                  short *current_index) {
    for (int i = 0; i < CASTLE_DIRECTIONS_NUMBER; ++i) {
        assign_direction_moves(state, coordinates, possible_moves, current_index, CASTLE_DIRECTIONS[i]);
    }
}