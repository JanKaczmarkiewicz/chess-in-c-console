#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "../game/game.h"

#define WHITE_SUBROW "\033[3;40;10m   %s   \033[0m"
#define BLACK_SUBROW "   %s   "

const short int NUMBER_OF_SUBROWS = 3;

char *get_chessman_code(struct Chessman *chessman) {
    switch (chessman->side) {
        case WHITE:
            switch (chessman->type) {
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
                default:
                    return "WHITE ERROR";
            }

        case BLACK:
            switch (chessman->type) {
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

                default:
                    return "BLACK ERROR";
            }
        case NONE:
            return " ";
    }

}

char *get_tile_code(bool is_white) {
    return is_white ? WHITE_SUBROW : BLACK_SUBROW;
}

void print_board(struct State *state) {
    for (short int subrow = 0; subrow < BOARD_SIZE * NUMBER_OF_SUBROWS; subrow++) {
        int row = floor(subrow / NUMBER_OF_SUBROWS);
        for (short int column = 0; column < BOARD_SIZE; column++) {

            bool is_white_tile = (column - row) % 2 == 0;
            bool is_subtile_with_object = subrow % NUMBER_OF_SUBROWS == 1;

            struct Chessman* currentChessman = &(state->board[row][column]);
            char *content = is_subtile_with_object ? get_chessman_code(currentChessman) : " ";

            printf(get_tile_code(is_white_tile), content);
        }
        printf("\n");
    }
}


#endif //DISPLAY_H
