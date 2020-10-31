#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "../game/game.h"

#define PRIMARY_SUBROW "\033[3;40;10m   %s   \033[0m"
#define SECONDARY_SUBROW "   %s   "
#define SELECTED_SUBROW "\033[3;46;35m  %s   \033[0m"
#define ALLOWED_SUBROW "\033[3;42;35m   %s   \033[0m"
#define CAPTURE_SUBROW "\033[3;41;35m   %s   \033[0m"

const short int NUMBER_OF_SUBROWS = 3;

char *get_chessman_code(struct Chessman *chessman) {
    switch (chessman->side) {
        case WHITE:
            switch (chessman->type) {
                case KING:
                    return "\u2654";
                case QUEEN:
                    return "\u2655";
                case PAWN:
                    return "\u2659";
                case KNIGHT:
                    return "\u2658";
                case CASTLE:
                    return "\u2656";
                case BISHOP:
                    return "\u2657";
            }

        case BLACK:
            switch (chessman->type) {
                case KING:
                    return "\u265A";
                case QUEEN:
                    return "\u265B";
                case PAWN:
                    return "\u265F";
                case KNIGHT:
                    return "\u265E";
                case CASTLE:
                    return "\u265C";
                case BISHOP:
                    return "\u265D";
            }
    }
}


struct Coordinates *create_coordinates(short x, short y) {
    struct Coordinates *coordinates = malloc(sizeof(struct Coordinates));
    coordinates->y = y;
    coordinates->x = x;
    return coordinates;
}

bool is_possible_move(struct State *state, enum Side chessman_side, short x, short y) {
    if (is_tile_not_exists(x, y)) return false;
    if (state->board[y][x] != NULL && state->board[y][x]->side == chessman_side) return false;
    return true;
}

short get_direction_next_x_modificator(enum Direction direction){
    switch(direction){
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

short get_direction_next_y_modificator(enum Direction direction){
    switch(direction){
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

void assign_direction_moves(struct State *state, struct Coordinates **possible_moves, enum Direction direction, short x, short y, enum Side chessman_side, short *current_index){
    for (short i = 1; i < BOARD_SIZE; ++i) {
        struct Coordinates *current = create_coordinates(
                x + i * get_direction_next_x_modificator(direction),
                y+ i * get_direction_next_y_modificator(direction)
                );

        if (!is_possible_move(state, chessman_side, current->x, current->y)) break;

        possible_moves[*current_index] = current;
        *current_index += 1;

        // it means that there is enemy out there
        if (state->board[current->y][current->x] != NULL) break;
    }
}

struct Coordinates **get_directions_possible_moves(struct State *state, enum Direction *directions, short number_of_directions, short x, short y) {
    struct Chessman *chessman=state->board[y][x];
    struct Coordinates **t_possible_moves = malloc(MAX_MOVES_NUMBER * sizeof(struct Coordinates *));
    short current_index = 0;

    for (short i= 0; i < number_of_directions; i++)
        assign_direction_moves(state, t_possible_moves, directions[i], x, y, chessman->side, &current_index);

    return t_possible_moves;
}

struct Coordinates **get_possible_moves(struct State *state, short x, short y) {
    switch (state->board[y][x]->type) {
//        case KING:
//            return get_king_possible_moves(board, x, y);
        case QUEEN:
            return get_directions_possible_moves(state, &QUEEN_DIRECTIONS, QUEEN_DIRECTIONS_NUMBER, x, y);
//        case PAWN:
//            return get_pawn_possible_moves(board, x, y);
//        case KNIGHT:
//            return get_knight_possible_moves(board, x, y);
        case CASTLE:
            return get_directions_possible_moves(state, &CASTLE_DIRECTIONS, CASTLE_DIRECTIONS_NUMBER, x, y);
        case BISHOP:
            return get_directions_possible_moves(state, &BISHOP_DIRECTIONS, BISHOP_DIRECTIONS_NUMBER, x, y);
    }
}


char *get_tile_code(bool is_selected_tile, bool is_prime_tile, bool is_possible_move_tile, bool is_possible_capture_tile) {
    if(is_possible_capture_tile)
        return CAPTURE_SUBROW;

    if (is_selected_tile)
        return SELECTED_SUBROW;

    if (is_possible_move_tile)
        return ALLOWED_SUBROW;

    return is_prime_tile ? PRIMARY_SUBROW : SECONDARY_SUBROW;
}

void print_board(struct State *state) {
    bool is_any_tile_is_selected = check_if_any_tile_is_selected(state);
    struct Coordinates **s = is_any_tile_is_selected
            ? get_possible_moves(state, state->selected_tile->x, state->selected_tile->y)
            : NULL;

    for (short subrow = 0; subrow < BOARD_SIZE * NUMBER_OF_SUBROWS; subrow++) {
        short row = floor(subrow / NUMBER_OF_SUBROWS);
        for (short column = 0; column < BOARD_SIZE; column++) {
            bool is_prime_tile = (column - row) % 2 == 0;
            bool is_current_subtile_middle = subrow % NUMBER_OF_SUBROWS == 1;
            bool is_current_tile_empty = is_tile_empty(state->board[row][column]);
            bool is_current_tile_selected = is_any_tile_is_selected
                    ? is_tile_selected(state, column, row)
                    : false;

            bool is_current_tile_in_possible_moves = is_any_tile_is_selected
                    ? is_in_possible_moves(s, column, row)
                    : false;

            bool is_current_tile_possible_capture = !is_current_tile_empty && is_current_tile_in_possible_moves;

            char *content = is_current_subtile_middle && !is_current_tile_empty
                    ? get_chessman_code(state->board[row][column])
                    : " ";

            char *tile_subrow = get_tile_code(is_current_tile_selected, is_prime_tile, is_current_tile_in_possible_moves, is_current_tile_possible_capture);

            printf(tile_subrow, content);
        }

        printf("\n");
    }
    free_possible_moves(s);
}


#endif //DISPLAY_H
