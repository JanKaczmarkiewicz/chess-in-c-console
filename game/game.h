#include <stdbool.h>
#include <stdlib.h>
#include "definitions.h"
#include "../helpers/helpers.h"

#include "queen.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "castle.h"

#ifndef GAME_H
#define GAME_H

//create chessman
struct Chessman *cc(enum Side side, enum ChessmanType chessman_type) {
    struct Chessman *chessman = malloc(sizeof(struct Chessman));
    chessman->type = chessman_type;
    chessman->side = side;
    return chessman;
}

void select_tile(struct State *state, short int x, short int y) {
    if (is_tile_not_exists(x, y)) return;
    if (is_tile_empty(state->board[y][x])) return;
    if (state->board[y][x]->side != state->current_side) return;

    free(state->selected_tile);

    struct Coordinates *selected_tile = malloc(sizeof(struct Coordinates) + 1);
    state->selected_tile = selected_tile;
    state->selected_tile->x = x;
    state->selected_tile->y = y;
}

struct Coordinates **get_possible_moves(struct State *state, short x, short y) {
    short current_index = 0;
    struct Coordinates **possible_moves = malloc(MAX_MOVES_NUMBER * sizeof(struct Coordinates *));

    switch (state->board[y][x]->type) {
        case KING:
            //assign_king_possible_moves(state, x, y, possible_moves, &current_index);
            break;

        case QUEEN:
            assign_queen_possible_moves(state, x, y, possible_moves, &current_index);
            break;

        case PAWN:
            assign_pawn_possible_moves(state, x, y, possible_moves, &current_index);
            break;

        case KNIGHT:
            assign_knight_possible_moves(state, x, y, possible_moves, &current_index);
            break;

        case CASTLE:
            assign_castle_possible_moves(state, x, y, possible_moves, &current_index);
            break;

        case BISHOP:
            assign_bishop_possible_moves(state, x, y, possible_moves, &current_index);
            break;
    }
    assign_end_to_possible_moves(possible_moves, &current_index);
    return possible_moves;
}


#endif //GAME_H
