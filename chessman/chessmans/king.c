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


void assign_king_possible_moves_base(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                                     short *current_index) {
    Side king_side = State_get_tile(state, coordinates)->side;

    for (short i = 0; i < KING_MOVES_DIRECTIONS_NUMBER; ++i) {

        Coordinates *current = Coordinates_p(
                coordinates->x + get_direction_next_x_modificator(KING_MOVE_DIRECTIONS[i]),
                coordinates->y + get_direction_next_y_modificator(KING_MOVE_DIRECTIONS[i])
        );

        if (!State_is_possible_move(state, current, king_side)) {
            free(current);
            continue;
        }

        assign_possible_move(possible_moves, current, current_index);
    }
}

void
assign_king_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                           short *current_index) {
    Side king_side = State_get_tile(state, coordinates)->side;

    bool is_king_on_current_side = king_side == state->current_side;

    if (!is_king_on_current_side) {
        assign_king_possible_moves_base(state, coordinates, possible_moves, current_index);
        return;
    }

    // +1 for case when will be 9 possible moves and NULL at the end
    Coordinates *temporary_king_possible_moves[KING_MOVES_DIRECTIONS_NUMBER + 1];
    short temporary_king_move_current_index = -1;

    assign_king_possible_moves_base(state, coordinates, temporary_king_possible_moves,
                                    &temporary_king_move_current_index);

    Coordinates **enemy_possible_moves = malloc(sizeof(Coordinates *) * 200);
    short enemy_possible_moves_counter = -1;


    for (short x = 0; x < BOARD_SIZE; ++x)
        for (short y = 0; y < BOARD_SIZE; ++y) {
            Coordinates *current = Coordinates_p(x, y);
            if (!State_is_tile_empty(state, current) && State_get_tile(state, current)->side != king_side)
                assign_chessman_possible_moves(state, current, enemy_possible_moves, &enemy_possible_moves_counter);

        }
    assign_possible_move(temporary_king_possible_moves, NULL, &temporary_king_move_current_index);

    for (short i = 0; i < KING_MOVES_DIRECTIONS_NUMBER + 1; ++i) {
        Coordinates *current_king_move = temporary_king_possible_moves[i];
        if (current_king_move == NULL) break;
        if (is_in_possible_moves(enemy_possible_moves, temporary_king_possible_moves[i])) {
            free(current_king_move);
            continue;
        }
        assign_possible_move(possible_moves, current_king_move, current_index);
    }

    free_possible_moves(enemy_possible_moves);
}