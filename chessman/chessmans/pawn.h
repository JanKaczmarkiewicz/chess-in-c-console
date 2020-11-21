#include "../../State/State.h"
#include "../../Coordinates/Coordinates.h"

#ifndef PAWN_H
#define PAWN_H

void assign_pawn_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                short *current_index);

#endif //PAWN_H
