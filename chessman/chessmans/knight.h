
#ifndef KNIGHT_H
#define KNIGHT_H

#include "../../State/State.h"
#include "../../Coordinates/Coordinates.h"
#include "../../helpers/possible_moves_helper.h"


void assign_knight_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                  short *current_index);

#endif //KNIGHT_H
