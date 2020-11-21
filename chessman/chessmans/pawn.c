#include "pawn.h"
#include "stdlib.h"
#include "../../helpers/possible_moves_helper.h"

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

        Coordinates *capture_move = Coordinates_p(
                coordinates->y + get_direction_next_y_modificator(pawn_capture_directions[i]),
                coordinates->x + get_direction_next_x_modificator(pawn_capture_directions[i])
        );

        if (!is_tile_exist(capture_move) || State_is_tile_empty(state, capture_move) ||
            State_get_tile(state, capture_move)->side == pawn_side){
            free(capture_move);
            continue;
        }

        assign_possible_move(possible_moves, capture_move, current_index);
    }

    //first possible move
    Coordinates *first_move = Coordinates_p(
            coordinates->x + get_direction_next_x_modificator(pawn_direction),
            coordinates->y + get_direction_next_y_modificator(pawn_direction)
    );

    if (!is_tile_exist(first_move) || !State_is_tile_empty(state, first_move)) {
        free(first_move);
        return;
    }

    assign_possible_move(possible_moves, first_move, current_index);

    //second possible move
    Coordinates *second_move = Coordinates_p(
            coordinates->x + 2 * get_direction_next_x_modificator(pawn_direction),
            coordinates->y + 2 * get_direction_next_y_modificator(pawn_direction)
    );

    if (!is_tile_exist(second_move) || special_row != coordinates->y || !State_is_tile_empty(state, second_move)) {
        free(second_move);
        return;
    }

    assign_possible_move(possible_moves, second_move, current_index);
}