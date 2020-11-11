#ifndef CONSTANTS_H
#define CONSTANTS_H

#define BOARD_SIZE 8
#define MAX_MOVES_NUMBER (BOARD_SIZE-1)*4
#define NUMBER_OF_SUBROWS 3

// TEXT COLORS
#define BLACK_TEXT "\033[38;5;8m"
#define RED_TEXT "\033[38;5;1m"
#define GREEN_TEXT "\033[38;5;30m"
#define BLUE_TEXT "\033[38;5;4m"

// BACKGROUND COLORS
#define GREY_BACKGROUND "\033[48;5;250m"
#define WHITE_BACKGROUND "\033[48;5;0m"

// CLEAR
#define CLEAR_BACKGROUND "\033[0m"
#define CLEAR_TEXT "\033[1m"

// CHESSMAN WRAPPERS
#define WHITE_CHESSMAN_COLOR(chessman_code) BLACK_TEXT""chessman_code""CLEAR_TEXT
#define BLACK_CHESSMAN_COLOR(chessman_code) BLACK_TEXT""chessman_code""CLEAR_TEXT

typedef struct {
    char *top;
    char *left;
    char *right;
    char *down;
} Subrow;

#endif //CONSTANTS_H
