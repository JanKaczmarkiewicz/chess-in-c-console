#include "stdlib.h"
#include "Coordinates.h"

Coordinates *Coordinates_p(short x, short y) {
    Coordinates *p = malloc(sizeof(Coordinates));
    p->y = y;
    p->x = x;
    return p;
}