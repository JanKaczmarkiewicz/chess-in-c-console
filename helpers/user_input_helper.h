#ifndef USER_INPUT_HELPER_H
#define USER_INPUT_HELPER_H

#include "../Coordinates/Coordinates.h"
#include "../State/State.h"

short translate_first_move_character(char c) {
    switch (c) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            return -1;
    }
}

short translate_second_move_character(char c) {
    switch (c) {
        case '8':
            return 0;
        case '7':
            return 1;
        case '6':
            return 2;
        case '5':
            return 3;
        case '4':
            return 4;
        case '3':
            return 5;
        case '2':
            return 6;
        case '1':
            return 7;
        default:
            return -1;
    }
}

Coordinates *get_user_move(Side side) {
    char input[2];
    printf("Please select %s chessman by command [a-g][1-8]:", side == WHITE ? "white" : "black");

    fgets(input, 3, stdin);

    short x = translate_first_move_character(input[0]);
    short y = translate_second_move_character(input[1]);

    if (x < 0 || y < 0) {
        printf("Please enter valid command\n");
        return NULL;
    }

    return Coordinates_p(x, y);
}

#endif //USER_INPUT_HELPER_H


