
#ifndef HELLO_CHESSMAN_H
#define HELLO_CHESSMAN_H

#include "../State/State.h"

enum ChessmanType {
    KING,
    QUEEN,
    PAWN,
    CASTLE,
    KNIGHT,
    BISHOP,
};

typedef struct Chessman {
    enum ChessmanType type;
    enum Side side;
} Chessman;

struct Chessman Chessman_value(enum Side side, enum ChessmanType type);

struct Chessman *Chessman_value_p(enum Side side, enum ChessmanType type);

char *Chessman_character(struct Chessman *self);




#endif //HELLO_CHESSMAN_H
