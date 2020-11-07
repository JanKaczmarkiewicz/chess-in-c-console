#include "../helpers/possible_moves_helper.h"

State State_value_initial() {
    State state = {
            .current_side = WHITE,
            .selected_tile = NULL,
            .board = {
                    //@formatter:off
                    {Chessman_p(BLACK, CASTLE), Chessman_p(BLACK, KNIGHT), Chessman_p(BLACK, BISHOP), Chessman_p(BLACK, KING), Chessman_p(BLACK, QUEEN), Chessman_p(BLACK,BISHOP), Chessman_p(BLACK, KNIGHT), Chessman_p(BLACK, CASTLE)},
                    {Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN), Chessman_p(BLACK, PAWN),  Chessman_p(BLACK,PAWN),   Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN)},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN), Chessman_p(WHITE, PAWN),  Chessman_p(WHITE,PAWN),   Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN),},
                    {Chessman_p(WHITE, CASTLE), Chessman_p(WHITE, KNIGHT), Chessman_p(WHITE, BISHOP), Chessman_p(WHITE, KING), Chessman_p(WHITE, QUEEN), Chessman_p(WHITE,BISHOP), Chessman_p(WHITE, KNIGHT), Chessman_p(WHITE, CASTLE)}
                    //@formatter:on
            }
    };
    return state;
}

Chessman *State_get_tile(State *self, Coordinates *coordinates) {
    return self->board[coordinates->y][coordinates->x];
}

bool State_is_tile_empty(State *self, Coordinates *coordinates) {
    return State_get_tile(self, coordinates) == NULL;
}

bool State_is_any_selected_tile(State *self) {
    return self->selected_tile != NULL;
}

bool State_is_possible_move(State *self, Coordinates *coordinates, Side chessman_side){
    if(State_is_tile_empty(self, coordinates)) return true;
    if(State_get_tile(self, coordinates)->side != chessman_side) return true;
    return false;
}

bool State_is_selected_tile(State *self, Coordinates *coordinates) {
    if (!State_is_any_selected_tile(self)) return false;
    return self->selected_tile->x == coordinates->x && self->selected_tile->y == coordinates->y;
}

bool is_tile_exist(Coordinates *coordinates) {
    return coordinates->x >= 0 && coordinates->x < BOARD_SIZE && coordinates->y >= 0 && coordinates->y < BOARD_SIZE;
}

void State_perform_action(State *self, Coordinates *coordinates) {
    if (is_tile_exist(coordinates)) return;
    if (State_is_tile_empty(self, coordinates)) return;
    if (State_get_tile(self, coordinates)->side != self->current_side) return;

    free(self->selected_tile);
    memcpy(self->selected_tile, coordinates, sizeof(Coordinates));
}

Coordinates **State_selected_chessman_possible_moves(State *self) {
    if (!State_is_any_selected_tile(self)) return NULL;
    return get_possible_moves(self, self->selected_tile);
}

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

void State_print_board(State *self) {
    Coordinates **possible_moves = State_selected_chessman_possible_moves(self);
    bool is_any_tile_is_selected = possible_moves == NULL;

    for (short subrow = 0; subrow < BOARD_SIZE * NUMBER_OF_SUBROWS; subrow++) {
        short y = floor(subrow / NUMBER_OF_SUBROWS);
        for (short x = 0; x < BOARD_SIZE; x++) {
            Coordinates *current_cords = Coordinates_p(x, y);

            bool is_prime_tile = (current_cords->x - current_cords->y) % 2 == 0;
            bool is_current_subtile_middle = subrow % NUMBER_OF_SUBROWS == 1;
            bool is_current_tile_empty = State_is_tile_empty(self, current_cords);
            bool is_current_tile_selected = is_any_tile_is_selected
                                            ? State_is_selected_tile(self, current_cords)
                                            : false;

            bool is_current_tile_in_possible_moves = is_any_tile_is_selected
                                                     ? is_in_possible_moves(possible_moves, current_cords)
                                                     : false;

            bool is_current_tile_possible_capture = !is_current_tile_empty && is_current_tile_in_possible_moves;

            char *content = is_current_subtile_middle && !is_current_tile_empty
                            ? Chessman_character(State_get_tile(self, current_cords))
                            : " ";

            char *tile_subrow = get_tile_code(is_current_tile_selected, is_prime_tile,
                                              is_current_tile_in_possible_moves, is_current_tile_possible_capture);

            printf(tile_subrow, content);
            free(current_cords);
        }

        printf("\n");
    }
    free_possible_moves(possible_moves);
}

Chessman *Chessman_p(Side side, ChessmanType type) {
    Chessman *p = malloc(sizeof(Chessman));
    p->side = side;
    p->type = type;
    return p;
}

char *Chessman_character(Chessman *self) {
    switch (self->side) {
        case WHITE:
            switch (self->type) {
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
            switch (self->type) {
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
            return "";
    }

}