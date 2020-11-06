#include "knight.h"

const short KNIGHT_MOVES_MODIFICATORS_NUMBER = 8;
Coordinates KNIGHT_MOVES_MODIFICATORS[KNIGHT_MOVES_MODIFICATORS_NUMBER] = {
        {-2, -1},
        {-2, 1},
        {-1, 2},
        {1,  2},
        {2,  1},
        {2,  -1},
        {1,  -2},
        {-1, -2}
};

void
assign_knight_possible_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves,
                             short *current_index) {
    for (short i = 0; i < KNIGHT_MOVES_MODIFICATORS_NUMBER; ++i) {

        Coordinates *current = Coordinates_p(
                coordinates->x + KNIGHT_MOVES_MODIFICATORS[i].x,
                coordinates->y + KNIGHT_MOVES_MODIFICATORS[i].y
        );

        if (!State_is_possible_move(state, coordinates, State_get_tile(state, coordinates)->side)) continue;

        possible_moves[*current_index++] = current;
    }
}