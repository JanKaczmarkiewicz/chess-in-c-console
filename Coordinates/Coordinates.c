#include "stdlib.h"
#include "Coordinates.h"

Coordinates *Coordinates_p(short x, short y) {
    Coordinates *p = malloc(sizeof(Coordinates));
    p->y = y;
    p->x = x;
    return p;
}

bool Coordinates_is_same_cord(Coordinates *self, Coordinates *coordinates){
    if(self == NULL || coordinates==NULL) return false;
    return self->x == coordinates->x && self->y == coordinates->y;
}