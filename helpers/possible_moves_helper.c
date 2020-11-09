#include "possible_moves_helper.h"

#include "../chessman/chessmans/bishop.h"
#include "../chessman/chessmans/castle.h"
#include "../chessman/chessmans/knight.h"
#include "../chessman/chessmans/pawn.h"
#include "../chessman/chessmans/queen.h"

void free_possible_moves(Coordinates **possible_moves) {
    if (possible_moves == NULL) return;
    for (int i = 0; i < MAX_MOVES_NUMBER; ++i) {
        if (possible_moves[i] == NULL) break;
        free(possible_moves[i]);
    }
    free(possible_moves);
}

bool is_in_possible_moves(Coordinates **possible_moves, Coordinates *coordinates) {
    if (possible_moves == NULL) return false;
    for (int i = 0; i < MAX_MOVES_NUMBER; ++i) {
        if (possible_moves[i] == NULL) return false;
        if (coordinates->x == possible_moves[i]->x && coordinates->y == possible_moves[i]->y) return true;
    }
    return false;
}

void assign_possible_move(Coordinates **possible_moves, Coordinates *coordinates, short *current_index) {
    possible_moves[++(*current_index)] = coordinates;
}

void assign_direction_moves(State *state, Coordinates *coordinates, Coordinates **possible_moves, short *current_index,
                            Direction direction) {
    Side chessman_side = State_get_tile(state, coordinates)->side;

    for (short i = 1; i < BOARD_SIZE; ++i) {
        Coordinates *current = Coordinates_p(
                coordinates->x + i * get_direction_next_x_modificator(direction),
                coordinates->y + i * get_direction_next_y_modificator(direction)
        );

        if (!State_is_possible_move(state, current, chessman_side)) break;

        assign_possible_move(possible_moves, current, current_index);

        // it means that there is enemy out there
        if (!State_is_tile_empty(state, current)) break;
    }
}

Coordinates **get_possible_moves(State *state, Coordinates *coordinates) {
    if (State_is_tile_empty(state, coordinates)) return NULL;

    short current_index = -1;
    Coordinates **possible_moves = malloc(MAX_MOVES_NUMBER * sizeof(Coordinates *));

    switch (State_get_tile(state, coordinates)->type) {
        case KING:
            //assign_king_possible_moves(state, coordinates, possible_moves, &current_index);
            break;

        case QUEEN:
            assign_queen_possible_moves(state, coordinates, possible_moves, &current_index);
            break;

        case PAWN:
            assign_pawn_possible_moves(state, coordinates, possible_moves, &current_index);
            break;

        case KNIGHT:
            assign_knight_possible_moves(state, coordinates, possible_moves, &current_index);
            break;

        case CASTLE:
            assign_castle_possible_moves(state, coordinates, possible_moves, &current_index);
            break;

        case BISHOP:
            assign_bishop_possible_moves(state, coordinates, possible_moves, &current_index);
            break;
    }

    if (current_index < 0) return NULL;

    assign_possible_move(possible_moves, NULL, &current_index);
    return possible_moves;
}