
#include "game/game.h"
#include "display/display.h"


int main() {

    struct Chessman board[BOARD_SIZE][BOARD_SIZE]={
            {cc(BLACK, CASTLE), cc(BLACK,KNIGHT), cc(BLACK,BISHOP), cc(BLACK, KING), cc(BLACK, QUEEN), cc(BLACK,BISHOP), cc(BLACK, KNIGHT), cc(BLACK, CASTLE)},
            {cc(BLACK, PAWN),cc(BLACK, PAWN),cc(BLACK, PAWN),cc(BLACK, PAWN),cc(BLACK, PAWN),cc(BLACK, PAWN),cc(BLACK, PAWN),cc(BLACK, PAWN)},
            {},
            {},
            {},
            {},
            {cc(WHITE, PAWN),cc(WHITE, PAWN),cc(WHITE, PAWN),cc(WHITE, PAWN),cc(WHITE, PAWN),cc(WHITE, PAWN),cc(WHITE, PAWN),cc(WHITE, PAWN),},
            {cc(WHITE, CASTLE), cc(WHITE,KNIGHT), cc(WHITE,BISHOP), cc(WHITE, KING), cc(WHITE, QUEEN), cc(WHITE,BISHOP), cc(WHITE, KNIGHT), cc(WHITE, CASTLE)}
    };

    print_board(board);
    return 0;
}
