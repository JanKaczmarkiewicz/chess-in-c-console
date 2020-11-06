#include "direction_helper.h"

short get_direction_next_x_modificator(enum Direction direction) {
    switch (direction) {
        case UP:
        case DOWN:
            return 0;
        case LEFT:
        case UP_LEFT:
        case DOWN_LEFT:
            return -1;
        case RIGHT:
        case UP_RIGHT:
        case DOWN_RIGHT:
            return 1;
    }
}

short get_direction_next_y_modificator(enum Direction direction) {
    switch (direction) {
        case UP_LEFT:
        case UP_RIGHT:
        case UP:
            return -1;
        case DOWN:
        case DOWN_LEFT:
        case DOWN_RIGHT:
            return 1;
        case LEFT:
        case RIGHT:
            return 0;
    }
}