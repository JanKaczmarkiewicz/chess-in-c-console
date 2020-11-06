#include "../../State/State.h"
#include "../../Coordinates/Coordinates.h"
#include "../../helpers/possible_moves_helper.h"

#ifndef BISHOP_H
#define BISHOP_H

void assign_bishop_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                  short *current_index);

#endif //BISHOP_H
