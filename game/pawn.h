#ifndef PAWN_H
#define PAWN_H

#include "definitions.h"
#include "../helpers/helpers.h"

const short WHITE_PAWN_SPECIAL_ROW = 6;
const short BLACK_PAWN_SPECIAL_ROW = 1;

const short PAWN_CAPTURE_DIRECTIONS_NUMBER = 2;

void assign_pawn_possible_moves(struct State *state, short x, short y, struct Coordinates **possible_moves,
                                short *current_index) {
    struct Chessman *pawn = state->board[y][x];

    bool is_pawn_white = pawn->side == WHITE;

    enum Direction pawn_direction = is_pawn_white ? UP : DOWN;
    enum Direction pawn_capture_directions[PAWN_CAPTURE_DIRECTIONS_NUMBER] = {is_pawn_white ? UP_LEFT : DOWN_LEFT,
                                                                              is_pawn_white ? UP_RIGHT : DOWN_RIGHT};

    short special_row = is_pawn_white ? WHITE_PAWN_SPECIAL_ROW : BLACK_PAWN_SPECIAL_ROW;

    //capture possible moves
    for (int i = 0; i < PAWN_CAPTURE_DIRECTIONS_NUMBER; i++) {
        short capture_coordinate_y = y + get_direction_next_y_modificator(pawn_capture_directions[i]);
        short capture_coordinate_x = x + get_direction_next_x_modificator(pawn_capture_directions[i]);

        if (is_tile_empty(state->board[capture_coordinate_y][capture_coordinate_x]) ||
            state->board[capture_coordinate_y][capture_coordinate_x]->side == pawn->side)
            break;

        possible_moves[*current_index] = create_coordinates(
                capture_coordinate_x,
                capture_coordinate_y
        );
        *current_index += 1;
    }

    //first possible move
    short first_move_coordinate_x = x + get_direction_next_x_modificator(pawn_direction);
    short first_move_coordinate_y = y + get_direction_next_y_modificator(pawn_direction);

    if (!is_tile_empty(state->board[first_move_coordinate_y][first_move_coordinate_x]))
        return;

    possible_moves[*current_index] = create_coordinates(
            first_move_coordinate_x,
            first_move_coordinate_y
    );
    *current_index += 1;

    //second possible move
    short second_move_coordinate_x = x + 2 * get_direction_next_x_modificator(pawn_direction);
    short second_move_coordinate_y = y + 2 * get_direction_next_y_modificator(pawn_direction);

    if (special_row != y || !is_tile_empty(state->board[second_move_coordinate_y][second_move_coordinate_x]))
        return;

    possible_moves[*current_index] = create_coordinates(
            second_move_coordinate_x,
            second_move_coordinate_y
    );
    *current_index += 1;
}

#endif //PAWN_H
