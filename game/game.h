#include <stdbool.h>
#include <stdlib.h>
#include "definitions.h"
#include "../helpers/helpers.h"

#ifndef GAME_H
#define GAME_H

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

    struct Coordinates *selected_tile = malloc(sizeof(struct Coordinates)+1);
    state->selected_tile = selected_tile;
    state->selected_tile->x = x;
    state->selected_tile->y = y;
}


#endif //GAME_H
