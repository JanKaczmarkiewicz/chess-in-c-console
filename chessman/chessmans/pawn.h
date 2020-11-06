#include "stdbool.h"
#include "../../State/State.h"
#include "../../Coordinates/Coordinates.h"
#include "../../helpers/possible_moves_helper.h"

#ifndef PAWN_H
#define PAWN_H

void assign_pawn_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                short *current_index);

#endif //PAWN_H
