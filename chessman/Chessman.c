#include "Chessman.h"
#include "stdlib.h"
#include "../constants.h"

Chessman *Chessman_p(Side side, ChessmanType type) {
    Chessman *p = malloc(sizeof(Chessman));
    p->side = side;
    p->type = type;
    return p;
}

char *Chessman_character(Chessman *self) {
    if (self == NULL) return " ";
    switch (self->side) {
        case WHITE:
            switch (self->type) {
                case KING:
                    return WHITE_CHESSMAN_COLOR("\u2654");
                case QUEEN:
                    return WHITE_CHESSMAN_COLOR("\u2655");
                case PAWN:
                    return WHITE_CHESSMAN_COLOR("\u2659");
                case KNIGHT:
                    return WHITE_CHESSMAN_COLOR("\u2658");
                case CASTLE:
                    return WHITE_CHESSMAN_COLOR("\u2656");
                case BISHOP:
                    return WHITE_CHESSMAN_COLOR("\u2657");
            }

        case BLACK:
            switch (self->type) {
                case KING:
                    return BLACK_CHESSMAN_COLOR("\u265A");
                case QUEEN:
                    return BLACK_CHESSMAN_COLOR("\u265B");
                case PAWN:
                    return BLACK_CHESSMAN_COLOR("\u265F");
                case KNIGHT:
                    return BLACK_CHESSMAN_COLOR("\u265E");
                case CASTLE:
                    return BLACK_CHESSMAN_COLOR("\u265C");
                case BISHOP:
                    return BLACK_CHESSMAN_COLOR("\u265D");
            }
    }
}