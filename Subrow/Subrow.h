#ifndef CHESS_SUBROW_H
#define CHESS_SUBROW_H

typedef struct {
    char *top;
    char *left;
    char *right;
    char *down;
} Subrow;

Subrow SIMPLE;

Subrow FRAME;

#endif //CHESS_SUBROW_H
