
#include "../../State/State.h"
#include "../../helpers/possible_moves_helper.h"

#ifndef QUEEN_H
#define QUEEN_H

void assign_queen_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                 short *current_index);

#endif //QUEEN_H
