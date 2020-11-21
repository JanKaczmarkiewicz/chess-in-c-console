#ifndef CHESS_CHESSMAN_H
#define CHESS_CHESSMAN_H

typedef enum {
    KING,
    QUEEN,
    PAWN,
    CASTLE,
    KNIGHT,
    BISHOP,
} ChessmanType;

typedef enum{
    WHITE,
    BLACK,
} Side;

typedef struct Chessman {
    ChessmanType type;
    Side side;
} Chessman;

Chessman *Chessman_p(Side, ChessmanType);

char *Chessman_character(Chessman *self);

#endif //CHESS_CHESSMAN_H
