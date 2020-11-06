cmake_minimum_required(VERSION 3.17)
project(hello C)

set(CMAKE_C_STANDARD 11)

add_executable(hello main.c display/display.h game/game.h game/definitions.h game/queen.h game/knight.h game/pawn.h game/castle.h game/bishop.h chessman/Chessman.h chessman/Chessman.c constants.h State/State.c Coordinates/Coordinates.h helpers/possible_moves_helper.h helpers/possible_moves_helper.c Coordinates/Coordinates.c helpers/direction_helper.c chessman/chessmans/bishop.c chessman/chessmans/castle.c chessman/chessmans/knight.c chessman/chessmans/pawn.c chessman/chessmans/queen.c)