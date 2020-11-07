cmake_minimum_required(VERSION 3.17)
project(hello C)

set(CMAKE_C_STANDARD 11)

add_executable(hello main.c State/State.c Coordinates/Coordinates.c helpers/possible_moves_helper.c Coordinates/Coordinates.c helpers/direction_helper.c chessman/chessmans/bishop.c chessman/chessmans/castle.c chessman/chessmans/knight.c chessman/chessmans/pawn.c chessman/chessmans/queen.c State/State.c Coordinates/Coordinates.c helpers/possible_moves_helper.c Coordinates/Coordinates.c helpers/direction_helper.c chessman/chessmans/bishop.c chessman/chessmans/castle.c chessman/chessmans/knight.c chessman/chessmans/pawn.c chessman/chessmans/queen.c)