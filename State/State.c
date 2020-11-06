#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "State.h"
#include "../chessman/Chessman.h"
#include "../Coordinates/Coordinates.h"

#include "../helpers/possible_moves_helper.h"


State State_value_initial() {
    State state = {
            .current_side = WHITE,
            .selected_tile = NULL,
            .board = {
                    //@formatter:off
                    {Chessman_value_p(BLACK, CASTLE), Chessman_value_p(BLACK, KNIGHT), Chessman_value_p(BLACK, BISHOP), Chessman_value_p(BLACK, KING), Chessman_value_p(BLACK, QUEEN), Chessman_value_p(BLACK,BISHOP), Chessman_value_p(BLACK, KNIGHT), Chessman_value_p(BLACK, CASTLE)},
                    {Chessman_value_p(BLACK, PAWN),   Chessman_value_p(BLACK, PAWN),   Chessman_value_p(BLACK, PAWN),   Chessman_value_p(BLACK, PAWN), Chessman_value_p(BLACK, PAWN),  Chessman_value_p(BLACK,PAWN),   Chessman_value_p(BLACK, PAWN),   Chessman_value_p(BLACK, PAWN)},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {Chessman_value_p(WHITE, PAWN),   Chessman_value_p(WHITE, PAWN),   Chessman_value_p(WHITE, PAWN),   Chessman_value_p(WHITE, PAWN), Chessman_value_p(WHITE, PAWN),  Chessman_value_p(WHITE,PAWN),   Chessman_value_p(WHITE, PAWN),   Chessman_value_p(WHITE, PAWN),},
                    {Chessman_value_p(WHITE, CASTLE), Chessman_value_p(WHITE, KNIGHT), Chessman_value_p(WHITE, BISHOP), Chessman_value_p(WHITE, KING), Chessman_value_p(WHITE, QUEEN), Chessman_value_p(WHITE,BISHOP), Chessman_value_p(WHITE, KNIGHT), Chessman_value_p(WHITE, CASTLE)}
                    //@formatter:on
            }
    };
    return state;
}

Chessman *State_get_tile(State *self, Coordinates *coordinates) {
    return self->board[coordinates->y][coordinates->x];
}

bool State_is_tile_empty(State *self, Coordinates *coordinates) {
    return State_get_tile(self, coordinates) != NULL;
}

bool State_is_any_selected_tile(State *self) {
    return self->selected_tile != NULL;
}

bool State_is_selected_tile(State *self, Coordinates *coordinates) {
    if (!State_is_any_selected_tile(self)) return false;
    return self->selected_tile->x == coordinates->x && self->selected_tile->y == coordinates->y;
}

bool is_tile_exist(Coordinates *coordinates) {
    return coordinates->x >= 0 && coordinates->x < BOARD_SIZE && coordinates->y >= 0 && coordinates->y < BOARD_SIZE;
}

void State_perform_action(State *self, Coordinates *coordinates) {
    if (is_tile_exist(coordinates)) return;
    if (State_is_tile_empty(self, coordinates)) return;
    if (State_get_tile(self, coordinates)->side != self->current_side) return;

    free(self->selected_tile);
    memcpy(self->selected_tile, coordinates, sizeof Coordinates);
}

Coordinates **State_selected_chessman_possible_moves(State *self) {
    if (!State_is_any_selected_tile(self)) return NULL;
    return get_possible_moves(self, self->selected_tile);
};

void State_print_board(State *self) {
    Coordinates **possible_moves = State_selected_chessman_possible_moves(self);
    bool is_any_tile_is_selected = possible_moves == NULL;

    for (short subrow = 0; subrow < BOARD_SIZE * NUMBER_OF_SUBROWS; subrow++) {
        short y = floor(subrow / NUMBER_OF_SUBROWS);
        for (short x = 0; x < BOARD_SIZE; x++) {
            bool is_prime_tile = (x - y) % 2 == 0;
            bool is_current_subtile_middle = subrow % NUMBER_OF_SUBROWS == 1;
            bool is_current_tile_empty = State_is_tile_empty(self, x, y);
            bool is_current_tile_selected = is_any_tile_is_selected
                                            ? State_is_selected_tile(self, x, y)
                                            : false;

            bool is_current_tile_in_possible_moves = is_any_tile_is_selected
                                                     ? is_in_possible_moves(possible_moves, x, y)
                                                     : false;

            bool is_current_tile_possible_capture = !is_current_tile_empty && is_current_tile_in_possible_moves;

            char *content = is_current_subtile_middle && !is_current_tile_empty
                            ? Chessman_character(self->board[x][y])
                            : " ";

            char *tile_subrow = get_tile_code(is_current_tile_selected, is_prime_tile,
                                              is_current_tile_in_possible_moves, is_current_tile_possible_capture);

            printf(tile_subrow, content);
        }

        printf("\n");
    }
    free_possible_moves(possible_moves);
};