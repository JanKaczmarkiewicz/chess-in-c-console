#include "knight.h"
#include "stdlib.h"

const short KING_MOVES_DIRECTIONS_NUMBER = 8;
Direction KING_MOVE_DIRECTIONS[KING_MOVES_DIRECTIONS_NUMBER] = {
        UP,
        DOWN,
        LEFT,
        UP_LEFT,
        DOWN_LEFT,
        RIGHT,
        UP_RIGHT,
        DOWN_RIGHT,
};

void
assign_king_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                             short *current_index) {
    Side king_side = State_get_tile(state, coordinates)->side;

    Coordinates enemy_possible_moves[100];

    for (short column = 0; column < BOARD_SIZE; ++column)
        for (short row = 0; row < BOARD_SIZE; ++row) {
            Coordinates
            if(State_is_tile_empty(state,))
        }



    for (short i = 0; i < KING_MOVES_DIRECTIONS_NUMBER; ++i) {

        Coordinates *current = Coordinates_p(
                coordinates->x + get_direction_next_x_modificator(KING_MOVE_DIRECTIONS[i]),
                coordinates->y + get_direction_next_y_modificator(KING_MOVE_DIRECTIONS[i])
        );

        if (!State_is_possible_move(state, current, king_side)){
            free(current);
            continue;
        }

        assign_possible_move(possible_moves, current, current_index);
    }
}