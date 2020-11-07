

#ifndef DIRECTION_HELPER_H
#define DIRECTION_HELPER_H
typedef enum {
    UP,
    DOWN,
    LEFT,
    UP_LEFT,
    DOWN_LEFT,
    RIGHT,
    UP_RIGHT,
    DOWN_RIGHT,
} Direction;

short get_direction_next_x_modificator(Direction direction);

short get_direction_next_y_modificator(Direction direction);


#endif //DIRECTION_HELPER_H