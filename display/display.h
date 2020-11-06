#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "../game/game.h"

char *
get_tile_code(bool is_selected_tile, bool is_prime_tile, bool is_possible_move_tile, bool is_possible_capture_tile) {
    if (is_possible_capture_tile)
        return CAPTURE_SUBROW;

    if (is_selected_tile)
        return SELECTED_SUBROW;

    if (is_possible_move_tile)
        return ALLOWED_SUBROW;

    return is_prime_tile ? PRIMARY_SUBROW : SECONDARY_SUBROW;
}

void print_board(struct State *state) {
    bool is_any_tile_is_selected = check_if_any_tile_is_selected(state);

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

            char *tile_subrow = get_tile_code(is_current_tile_selected, is_prime_tile,
                                              is_current_tile_in_possible_moves, is_current_tile_possible_capture);

            printf(tile_subrow, content);
        }

        printf("\n");
    }
    free_possible_moves(s);
}


#endif //DISPLAY_H
