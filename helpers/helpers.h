#include <stdbool.h>
#include <stdlib.h>
#include "../game/definitions.h"


#ifndef HELPERS_H
#define HELPERS_H


short get_direction_next_x_modificator(enum Direction direction) {
    switch (direction) {
        case UP:
        case DOWN:
            return 0;
        case LEFT:
        case UP_LEFT:
        case DOWN_LEFT:
            return -1;
        case RIGHT:
        case UP_RIGHT:
        case DOWN_RIGHT:
            return 1;
    }
}

short get_direction_next_y_modificator(enum Direction direction) {
    switch (direction) {
        case UP_LEFT:
        case UP_RIGHT:
        case UP:
            return -1;
        case DOWN:
        case DOWN_LEFT:
        case DOWN_RIGHT:
            return 1;
        case LEFT:
        case RIGHT:
            return 0;
    }
}

struct Coordinates *create_coordinates(short x, short y) {
    struct Coordinates *coordinates = malloc(sizeof(struct Coordinates));
    coordinates->y = y;
    coordinates->x = x;
    return coordinates;
}

bool is_tile_empty(struct Chessman *chessman) {
    return chessman == NULL;
}

bool is_tile_not_exists(short x, short y) {
    return !(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

bool is_possible_move(struct State *state, enum Side chessman_side, short x, short y) {
    if (is_tile_not_exists(x, y)) return false;
    if (!is_tile_empty(state->board[y][x]) && state->board[y][x]->side == chessman_side) return false;
    return true;
}

bool is_tile_selected(struct State *state, short x, short y) {
    return state->selected_tile->x == x && state->selected_tile->y == y;
}

struct Chessman *get_selected_chessman(struct State *state) {
    return state->board[state->selected_tile->x][state->selected_tile->y];
}

void free_possible_moves(struct Coordinates **possible_moves) {
    if(possible_moves == NULL) return;
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

void assign_end_to_possible_moves(struct Coordinates **possible_moves, short *current_index) {
    possible_moves[*current_index + 1] = NULL;
}

void assign_direction_moves(struct State *state, short x,
                            short y, struct Coordinates **possible_moves, short *current_index,
                            enum Direction direction, enum Side chessman_side) {
    for (short i = 1; i < BOARD_SIZE; ++i) {
        struct Coordinates *current = create_coordinates(
                x + i * get_direction_next_x_modificator(direction),
                y + i * get_direction_next_y_modificator(direction)
        );

        if (!is_possible_move(state, chessman_side, current->x, current->y)) break;

        possible_moves[*current_index] = current;
        *current_index += 1;

        // it means that there is enemy out there
        if (state->board[current->y][current->x] != NULL) break;
    }
}

void
assign_directions_possible_moves(struct State *state, short x, short y, struct Coordinates **possible_moves,
                                 short *current_index, enum Direction *directions, short number_of_directions) {
    struct Chessman *chessman = state->board[y][x];

    for (short i = 0; i < number_of_directions; i++)
        assign_direction_moves(state, x, y, possible_moves, current_index, directions[i], chessman->side);
}


#endif // HELPERS_H
