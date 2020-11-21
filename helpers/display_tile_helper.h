#ifndef CHESS_DISPLAY_TILE_HELPER_H
#define CHESS_DISPLAY_TILE_HELPER_H

#include <stdbool.h>
#include "../Coordinates/Coordinates.h"

char *get_frame_color(bool is_selected, bool is_possible_move, bool is_possible_capture);

char *get_background_color(Coordinates *coordinates);

char *get_tile_code(int subrow, char *background_color, char *frame_color, char *content);

#endif //CHESS_DISPLAY_TILE_HELPER_H
