#include <stdlib.h>
#include "Chessman.h"

struct Chessman Chessman_value(enum Side side, enum ChessmanType type) {
    struct Chessman initialized = {type, side};
    return initialized;
};

struct Chessman *Chessman_value_p(enum Side side, enum ChessmanType type) {
    struct Chessman *initialized = malloc(sizeof(struct Chessman));
    initialized->side = side;
    initialized->type = type;
    return initialized;
};

char *Chessman_character(struct Chessman *self) {
    switch (self->side) {
        case WHITE:
            switch (self->type) {
                case KING:
                    return "\u2654";
                case QUEEN:
                    return "\u2655";
                case PAWN:
                    return "\u2659";
                case KNIGHT:
                    return "\u2658";
                case CASTLE:
                    return "\u2656";
                case BISHOP:
                    return "\u2657";
            }

        case BLACK:
            switch (self->type) {
                case KING:
                    return "\u265A";
                case QUEEN:
                    return "\u265B";
                case PAWN:
                    return "\u265F";
                case KNIGHT:
                    return "\u265E";
                case CASTLE:
                    return "\u265C";
                case BISHOP:
                    return "\u265D";
            }
    }
};
