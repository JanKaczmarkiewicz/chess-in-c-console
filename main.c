#include "game/game.h"
#include "display/display.h"


int main() {
    struct State state = {
            .current_turn = WHITE,
            .selected_tile = {-1, -1},
            .board = {
                    //@formatter:off
                    {cc(BLACK, CASTLE), cc(BLACK, KNIGHT), cc(BLACK, BISHOP), cc(BLACK, KING), cc(BLACK, QUEEN), cc(BLACK,BISHOP), cc(BLACK, KNIGHT), cc(BLACK, CASTLE)},
                    {cc(BLACK, PAWN),   cc(BLACK, PAWN),   cc(BLACK, PAWN),   cc(BLACK, PAWN), cc(BLACK, PAWN),  cc(BLACK,PAWN),   cc(BLACK, PAWN),   cc(BLACK, PAWN)},
                    {cc(NONE, EMPTY),   cc(NONE, EMPTY),   cc(NONE, EMPTY),   cc(NONE, EMPTY), cc(NONE, EMPTY),  cc(NONE, EMPTY),  cc(NONE, EMPTY),   cc(NONE, EMPTY)},
                    {cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY)},
                    {cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY)},
                    {cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY),cc(NONE, EMPTY)},
                    {cc(WHITE, PAWN),   cc(WHITE, PAWN),   cc(WHITE, PAWN),   cc(WHITE, PAWN), cc(WHITE, PAWN),  cc(WHITE,PAWN),   cc(WHITE, PAWN),   cc(WHITE, PAWN),},
                    {cc(WHITE, CASTLE), cc(WHITE, KNIGHT), cc(WHITE, BISHOP), cc(WHITE, KING), cc(WHITE, QUEEN), cc(WHITE,BISHOP), cc(WHITE, KNIGHT), cc(WHITE, CASTLE)}
                    //@formatter:on
            }
    };

    print_board(&state);
    return 0;
}
