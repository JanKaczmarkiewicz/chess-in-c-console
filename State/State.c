#include "../helpers/possible_moves_helper.h"

Subrow SIMPLE = {
        .top="       ",
        .left="   ",
        .right="   ",
        .down="       "};
Subrow FRAME = {
        .top="╔═════╗",
        .left="║  ",
        .right="  ║",
        .down="╚═════╝"};

State State_value_initial() {
    State state = {
            .current_side = WHITE,
            .selected_tile = NULL,
            .board = {
                    //@formatter:off
                    {Chessman_p(BLACK, CASTLE), Chessman_p(BLACK, KNIGHT), Chessman_p(BLACK, BISHOP), Chessman_p(BLACK, KING), Chessman_p(BLACK, QUEEN), Chessman_p(BLACK,BISHOP), Chessman_p(BLACK, KNIGHT), Chessman_p(BLACK, CASTLE)},
                    {Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN), Chessman_p(BLACK, PAWN),  Chessman_p(BLACK,PAWN),   Chessman_p(BLACK, PAWN),   Chessman_p(BLACK, PAWN)},
                    {Chessman_p(WHITE, PAWN),   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,  NULL,   NULL,   NULL,   NULL},
                    {NULL,   Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN), Chessman_p(WHITE, PAWN),  Chessman_p(WHITE,PAWN),   Chessman_p(WHITE, PAWN),   Chessman_p(WHITE, PAWN),},
                    {Chessman_p(WHITE, CASTLE), Chessman_p(WHITE, KNIGHT), Chessman_p(WHITE, BISHOP), Chessman_p(WHITE, KING), Chessman_p(WHITE, QUEEN), Chessman_p(WHITE,BISHOP), Chessman_p(WHITE, KNIGHT), Chessman_p(WHITE, CASTLE)}
                    //@formatter:on
            }
    };
    return state;
}

bool is_tile_exist(Coordinates *coordinates) {
    return coordinates->x >= 0 && coordinates->x < BOARD_SIZE && coordinates->y >= 0 && coordinates->y < BOARD_SIZE;
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

bool State_is_possible_move(State *self, Coordinates *coordinates, Side chessman_side) {
    if (!is_tile_exist(coordinates)) return false;
    if (State_is_tile_empty(self, coordinates)) return true;
    if (State_get_tile(self, coordinates)->side != chessman_side) return true;
    return false;
}

bool State_is_selected_tile(State *self, Coordinates *coordinates) {
    if (!State_is_any_selected_tile(self)) return false;
    return Coordinates_is_same_cord(self->selected_tile, coordinates);

}

Coordinates **State_selected_chessman_possible_moves(State *self) {
    if (!State_is_any_selected_tile(self)) return NULL;
    return get_possible_moves(self, self->selected_tile);
}

void State_perform_action(State *self, Coordinates *coordinates) {
    if (!is_tile_exist(coordinates)) return;

    Coordinates **possible_moves = State_selected_chessman_possible_moves(self);
    bool is_move_phase = is_in_possible_moves(possible_moves, coordinates);
    free_possible_moves(possible_moves);

    if (Coordinates_is_same_cord(self->selected_tile, coordinates))
        return;

    if (is_move_phase) {
        self->board[coordinates->y][coordinates->x] = State_get_tile(self, self->selected_tile);
        self->board[self->selected_tile->y][self->selected_tile->x] = NULL;
        free(self->selected_tile);
        self->selected_tile = NULL;
        self->current_side = self->current_side == WHITE ? BLACK : WHITE;
        return;
    }

    if (State_is_tile_empty(self, coordinates)) return;
    if (State_get_tile(self, coordinates)->side != self->current_side) return;

    free(self->selected_tile);
    self->selected_tile = Coordinates_p(coordinates->x, coordinates->y);
}


char *
get_tile_code(int subrow, char *background_color, char *frame_color, char *content) {
    char *result=malloc(sizeof(char) * 70);
    Subrow subrow_content = frame_color == NULL ? SIMPLE : FRAME;

    if(frame_color == NULL)
        frame_color="";


    strcat(result, background_color);
    strcat(result, frame_color);

    if (subrow == 0)
        strcat(result, subrow_content.top);
    else if (subrow == 1){
        strcat(result, subrow_content.left);
        strcat(result, content);
        strcat(result, frame_color);
        strcat(result, subrow_content.right);
    }
    else if (subrow == 2)
        strcat(result, subrow_content.down);

    strcat(result, CLEAR_BACKGROUND);

    return result;
}

char *get_frame_color(bool is_selected, bool is_possible_move, bool is_possible_capture) {
    if (is_selected)
        return BLUE_TEXT;
    if (is_possible_capture)
        return RED_TEXT;
    if (is_possible_move)
        return GREEN_TEXT;
    return NULL;
}

void State_print_board(State *self) {
    Coordinates **possible_moves = State_selected_chessman_possible_moves(self);

    for (short subrow = 0; subrow < BOARD_SIZE * NUMBER_OF_SUBROWS; subrow++) {
        short y = floor(subrow / NUMBER_OF_SUBROWS);
        for (short x = 0; x < BOARD_SIZE; ++x) {
            Coordinates *current_cords = Coordinates_p(x, y);

            bool is_current_tile_selected = State_is_selected_tile(self, current_cords);
            bool is_current_tile_in_possible_moves = is_in_possible_moves(possible_moves, current_cords);
            bool is_current_tile_possible_capture =
                    !State_is_tile_empty(self, current_cords) && is_current_tile_in_possible_moves;

            char *background_color =
                    (current_cords->x - current_cords->y) % 2 == 0 ? WHITE_BACKGROUND : GREY_BACKGROUND;
            char *frame_color = get_frame_color(is_current_tile_selected, is_current_tile_in_possible_moves,
                                               is_current_tile_possible_capture);
            char *content = Chessman_character(State_get_tile(self, current_cords));

            char *tile_subrow = get_tile_code(subrow % NUMBER_OF_SUBROWS, background_color, frame_color, content);

            printf(tile_subrow);
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
    if (self == NULL) return " ";
    switch (self->side) {
        case WHITE:
            switch (self->type) {
                case KING:
                    return WHITE_CHESSMAN_COLOR("\u2654");
                case QUEEN:
                    return WHITE_CHESSMAN_COLOR("\u2655");
                case PAWN:
                    return WHITE_CHESSMAN_COLOR("\u2659");
                case KNIGHT:
                    return WHITE_CHESSMAN_COLOR("\u2658");
                case CASTLE:
                    return WHITE_CHESSMAN_COLOR("\u2656");
                case BISHOP:
                    return WHITE_CHESSMAN_COLOR("\u2657");
            }

        case BLACK:
            switch (self->type) {
                case KING:
                    return BLACK_CHESSMAN_COLOR("\u265A");
                case QUEEN:
                    return BLACK_CHESSMAN_COLOR("\u265B");
                case PAWN:
                    return BLACK_CHESSMAN_COLOR("\u265F");
                case KNIGHT:
                    return BLACK_CHESSMAN_COLOR("\u265E");
                case CASTLE:
                    return BLACK_CHESSMAN_COLOR("\u265C");
                case BISHOP:
                    return BLACK_CHESSMAN_COLOR("\u265D");
            }
    }

}