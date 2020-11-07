#include "pawn.h"

const short WHITE_PAWN_SPECIAL_ROW = 6;
const short BLACK_PAWN_SPECIAL_ROW = 1;

const short PAWN_CAPTURE_DIRECTIONS_NUMBER = 2;

void assign_pawn_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                short *current_index) {
    Side pawn_side = State_get_tile(state, coordinates)->side;

    bool is_pawn_white = pawn_side == WHITE;

    Direction pawn_direction = is_pawn_white ? UP : DOWN;
    Direction pawn_capture_directions[PAWN_CAPTURE_DIRECTIONS_NUMBER] = {is_pawn_white ? UP_LEFT : DOWN_LEFT,
                                                                         is_pawn_white ? UP_RIGHT : DOWN_RIGHT};

    short special_row = is_pawn_white ? WHITE_PAWN_SPECIAL_ROW : BLACK_PAWN_SPECIAL_ROW;

    //capture possible moves
    for (int i = 0; i < PAWN_CAPTURE_DIRECTIONS_NUMBER; i++) {
        short capture_coordinate_y = coordinates->y + get_direction_next_y_modificator(pawn_capture_directions[i]);
        short capture_coordinate_x = coordinates->x + get_direction_next_x_modificator(pawn_capture_directions[i]);

        if (State_is_tile_empty(state, coordinates) ||
            state->board[capture_coordinate_y][capture_coordinate_x]->side == pawn_side)
            break;

        possible_moves[*current_index++] = Coordinates_p(
                capture_coordinate_x,
                capture_coordinate_y
        );
    }

    //first possible move
    short first_move_coordinate_x = coordinates->x + get_direction_next_x_modificator(pawn_direction);
    short first_move_coordinate_y = coordinates->y + get_direction_next_y_modificator(pawn_direction);

    if (!State_is_tile_empty(state, coordinates))
        return;

    possible_moves[*current_index++] = Coordinates_p(
            first_move_coordinate_x,
            first_move_coordinate_y
    );

    //second possible move
    short second_move_coordinate_x = coordinates->x + 2 * get_direction_next_x_modificator(pawn_direction);
    short second_move_coordinate_y = coordinates->y + 2 * get_direction_next_y_modificator(pawn_direction);

    if (special_row != coordinates->y || !State_is_tile_empty(state, coordinates))
        return;

    possible_moves[*current_index++] = Coordinates_p(
            second_move_coordinate_x,
            second_move_coordinate_y
    );
}