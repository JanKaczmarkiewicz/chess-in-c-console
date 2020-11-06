
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

const short BISHOP_DIRECTIONS_NUMBER = 4;
Direction BISHOP_DIRECTIONS[BISHOP_DIRECTIONS_NUMBER]= {UP_RIGHT, UP_LEFT, DOWN_LEFT, DOWN_RIGHT};

short get_direction_next_x_modificator(Direction direction);

short get_direction_next_y_modificator(Direction direction);