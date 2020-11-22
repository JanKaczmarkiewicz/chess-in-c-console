cmake_minimum_required(VERSION 3.17)
project(chess C)

set(CMAKE_C_STANDARD 11)

add_executable(chess main.c State/State.c Coordinates/Coordinates.c helpers/possible_moves_helper.c Coordinates/Coordinates.c helpers/direction_helper.c chessman/chessmans/bishop.c chessman/chessmans/castle.c chessman/chessmans/knight.c chessman/chessmans/pawn.c chessman/chessmans/queen.c State/State.c Coordinates/Coordinates.c helpers/possible_moves_helper.c Coordinates/Coordinates.c helpers/direction_helper.c chessman/chessmans/bishop.c chessman/chessmans/castle.c chessman/chessmans/knight.c chessman/chessmans/pawn.c chessman/chessmans/queen.c chessman/Chessman.h Chessman/Chessman.c Subrow/Subrow.h helpers/display_tile_helper.c helpers/display_tile_helper.h Subrow/Subrow.c Chessman/chessmans/king.h Chessman/chessmans/king.c)