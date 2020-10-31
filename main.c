#include "game/game.h"
#include "display/display.h"


int main() {
    struct State state = {
            .current_side = WHITE,
            .selected_tile = NULL,
            .board = {
                    //@formatter:off
                    {cc(BLACK, CASTLE), cc(BLACK, KNIGHT), cc(BLACK, BISHOP), cc(BLACK, KING), cc(BLACK, QUEEN), cc(BLACK,BISHOP), cc(BLACK, KNIGHT), cc(BLACK, CASTLE)},
                    {cc(BLACK, PAWN),   cc(BLACK, PAWN),   cc(BLACK, PAWN),   cc(BLACK, PAWN), cc(BLACK, PAWN),  cc(BLACK,PAWN),   cc(BLACK, PAWN),   cc(BLACK, PAWN)},
                    {NULL,   NULL,   NULL,   NULL, NULL,  NULL,  NULL,   NULL},
                    {NULL,   NULL,   NULL,   NULL,NULL,NULL,NULL,NULL},
                    {NULL,   NULL,   NULL,   cc(WHITE, KNIGHT),NULL,NULL,NULL,NULL},
                    {NULL,   NULL,   NULL,   NULL,NULL,NULL,NULL,NULL},
                    {cc(WHITE, PAWN),   cc(WHITE, PAWN),   cc(WHITE, PAWN),   cc(WHITE, PAWN), cc(WHITE, PAWN),  cc(WHITE,PAWN),   cc(WHITE, PAWN),   cc(WHITE, PAWN),},
                    {cc(WHITE, CASTLE), cc(WHITE, KNIGHT), cc(WHITE, BISHOP), cc(WHITE, KING), cc(WHITE, QUEEN), cc(WHITE,BISHOP), cc(WHITE, KNIGHT), cc(WHITE, CASTLE)}
                    //@formatter:on
            }
    };


    select_tile(&state, 3, 4);

    print_board(&state);
    return 0;
}
