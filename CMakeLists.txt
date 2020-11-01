cmake_minimum_required(VERSION 3.17)
project(hello C)

set(CMAKE_C_STANDARD 11)

add_executable(hello main.c display/display.h game/game.h helpers/helpers.h game/definitions.h game/queen.h game/knight.h game/pawn.h game/castle.h game/bishop.h)