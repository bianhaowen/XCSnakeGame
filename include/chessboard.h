#ifndef __CHESSBOARD_H__
#define __CHESSBOARD_H__

#include <stdbool.h>
#include <stdint.h>

#include "../include/coordinates.h"
#include "../include/definition.h"

#define CHESSBOARD_SIZE_X (size_t)20
#define CHESSBOARD_SIZE_Y (size_t)60

typedef struct Chessboard
{
    Coordinates head;
    Coordinates tail;
    Coordinates food;
    char board[CHESSBOARD_SIZE_X][CHESSBOARD_SIZE_Y];
} Chessboard;

void rendering_chessboard(Chessboard *chessboard, bool eated_food);
void print_chessboard(const Chessboard *const chessboard);

#endif
