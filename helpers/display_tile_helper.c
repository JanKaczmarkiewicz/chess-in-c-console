#include "string.h"
#include "stdlib.h"

#include "display_tile_helper.h"

#include "../constants.h"
#include "../Subrow/Subrow.h"


char *get_frame_color(bool is_selected, bool is_possible_move, bool is_possible_capture) {
    if (is_selected)
        return BLUE_TEXT;
    if (is_possible_capture)
        return RED_TEXT;
    if (is_possible_move)
        return GREEN_TEXT;
    return NULL;
}

char *get_background_color(Coordinates *coordinates) {
    return (coordinates->x - coordinates->y) % 2 == 0 ? WHITE_BACKGROUND : GREY_BACKGROUND;
}

char *
get_tile_code(int subrow, char *background_color, char *frame_color, char *content) {
    char *result = malloc(sizeof(char) * 70);
    Subrow subrow_content = frame_color == NULL ? SIMPLE : FRAME;

    if (frame_color == NULL)
        frame_color = "";

    strcat(result, background_color);
    strcat(result, frame_color);

    if (subrow == 0)
        strcat(result, subrow_content.top);
    else if (subrow == 1) {
        strcat(result, subrow_content.left);
        strcat(result, content);
        strcat(result, frame_color);
        strcat(result, subrow_content.right);
    } else if (subrow == 2)
        strcat(result, subrow_content.down);

    strcat(result, CLEAR_BACKGROUND);

    return result;
}