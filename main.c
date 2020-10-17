#include <stdio.h>
#include <stdlib.h>


const short int BOARD_WIDTH = 8;
const short int BOARD_HEIGHT = 8;

enum ChessmanType {
    KING,
    QUEEN,
    PAWN,
    CASTLE,
    KNIGHT,
    BISHOP,
};

enum Side {
    WHITE,
    BLACK,
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

struct Chessman{
    enum ChessmanType type;
    enum Side side;
};


int* create_board(){
    struct Chessman*
}

void print_board(){

}


struct Chessman create_chessman(enum Side side, enum ChessmanType chessmanType){
    struct Chessman chessman;
    chessman.side=side;
    chessman.type=chessmanType;
    return chessman;
}

int main() {
    struct Chessman chessman = create_chessman(WHITE, BISHOP);
    return 0;
}
