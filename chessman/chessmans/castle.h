#include "../../State/State.h"
#include "../../Coordinates/Coordinates.h"
#include "../../helpers/possible_moves_helper.h"

#ifndef CASTLE_H
#define CASTLE_H

void assign_castle_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                  short *current_index);

#endif //CASTLE_H
