#include <stdbool.h>
#include <stdlib.h>
#include "../game/definitions.h"


#ifndef HELPERS_H
#define HELPERS_H

bool is_tile_empty(struct Chessman *chessman) {
    return chessman == NULL;
}

bool is_tile_not_exists(short x, short y) {
    return !(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

bool is_tile_selected(struct State *state, short x, short y) {
    return state->selected_tile->x == x && state->selected_tile->y == y;
}

struct Chessman *get_selected_chessman(struct State *state) {
    return state->board[state->selected_tile->x][state->selected_tile->y];
}

void free_possible_moves(struct Coordinates **possible_moves) {
    for (short i = 0; i < MAX_MOVES_NUMBER; i++) {
        free(possible_moves[i]);
    }
    free(possible_moves);
}

bool is_in_possible_moves(struct Coordinates **possible_moves, short x, short y) {
    for (short i = 0; i < MAX_MOVES_NUMBER; i++) {
        if (possible_moves[i] == NULL) break;
        if (possible_moves[i]->x == x && possible_moves[i]->y == y) return true;
    }
    return false;
}

bool check_if_any_tile_is_selected(struct State *state) {
    return state->selected_tile != NULL;
}


#endif // HELPERS_H
