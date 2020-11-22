#ifndef POSSIBLE_MOVES_HELPER_H
#define POSSIBLE_MOVES_HELPER_H

#include <stdbool.h>
#include "../Coordinates/Coordinates.h"
#include "../State/State.h"
#include "direction_helper.h"

void free_possible_moves(Coordinates **possible_moves);

void assign_possible_move(Coordinates **possible_moves, Coordinates *coordinates, short *current_index);

void assign_direction_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves, short *current_index,
                            Direction direction);

void assign_chessman_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                    short *current_index);

Coordinates **get_possible_moves(State *state, Coordinates *coordinates);

bool is_in_possible_moves(Coordinates **possible_moves, Coordinates *coordinates);

#endif //POSSIBLE_MOVES_HELPER_H
