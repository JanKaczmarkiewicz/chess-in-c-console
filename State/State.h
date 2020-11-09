#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../constants.h"
#include "../Coordinates/Coordinates.h"


typedef enum{
    WHITE,
    BLACK,
} Side;

typedef enum {
    KING,
    QUEEN,
    PAWN,
    CASTLE,
    KNIGHT,
    BISHOP,
} ChessmanType;

typedef struct Chessman {
    ChessmanType type;
    Side side;
} Chessman;

Chessman *Chessman_p(Side side, ChessmanType type);

char *Chessman_character(Chessman *self);

typedef struct {
    Side current_side;
    Coordinates *selected_tile;
    Chessman *board[BOARD_SIZE][BOARD_SIZE];
} State;

State State_value_initial();

void State_perform_action(State *self, Coordinates *coordinate);

void State_print_board(State *self);

bool is_tile_exist(Coordinates *coordinates);

bool State_is_tile_empty(State *self, Coordinates *coordinates);

bool State_is_possible_move(State *self, Coordinates *coordinates, Side chessman_side);

Chessman *State_get_tile(State *self, Coordinates *coordinates);

#endif
