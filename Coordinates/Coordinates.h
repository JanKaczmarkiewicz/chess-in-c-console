

#ifndef COORDINATES_H
#define COORDINATES_H

#include <stdbool.h>

typedef struct {
    short x;
    short y;
} Coordinates;

Coordinates *Coordinates_p(short x, short y);

Coordinates Coordinates_v(short x, short y);

bool Coordinates_is_same_cord(Coordinates *self, Coordinates *coordinates);

#endif //COORDINATES_H
