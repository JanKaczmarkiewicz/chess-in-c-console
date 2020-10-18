//
// Created by Jan Kaczmarkiewicz on 18/10/2020.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "../game/game.h"

#define WHITE_SUBROW "\033[3;40;10m   %s   \033[0m"
#define BLACK_SUBROW "   %s   "

const short int NUMBER_OF_SUBROWS= 3;

char* get_chessman_code(struct Chessman* chessman){
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
            }
            return "";
    }

}

char* get_tile_code (bool is_white) {
    return is_white ? WHITE_SUBROW : BLACK_SUBROW;
}

void print_board(struct Chessman **board[BOARD_SIZE][BOARD_SIZE]){
    for (short int t_i = 0; t_i < BOARD_SIZE * NUMBER_OF_SUBROWS; t_i++){
        int i = floor(t_i / NUMBER_OF_SUBROWS);
        for (short int j = 0; j < BOARD_SIZE; j++){
            bool is_white_tile  = (i-j) % 2 == 0;

            bool is_subtile_with_chessman = !(board[i][j] == NULL) && (t_i % NUMBER_OF_SUBROWS == 1);

            char* content = is_subtile_with_chessman ? get_chessman_code(&(board[i][j])) : " ";

            printf(get_tile_code(is_white_tile), content);
        }
        printf("\n");
    }
}


#endif //DISPLAY_H
