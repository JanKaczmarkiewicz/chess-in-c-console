
#ifndef STATE_H
#define STATE_H

#include "../constants.h"
#include "../chessman/Chessman.h"
#include "../Coordinates/Coordinates.h"

enum Side {
    WHITE,
    BLACK,
};

typedef struct {
    enum Side current_side;
    Coordinates *selected_tile;
    Chessman *board[BOARD_SIZE][BOARD_SIZE];
} State;

State State_value_initial();

void State_perform_action(State *self, Coordinates *coordinate);

void State_print_board(State *self);

bool State_is_tile_empty(State *self, Coordinates *coordinates);

Chessman *State_get_tile(State *self, Coordinates *coordinates);

bool State_is_possible_move(State *self, Coordinates *coordinates, enum Side chessman_side);



#endif
