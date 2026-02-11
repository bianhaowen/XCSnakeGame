#include <stdbool.h>
#include <stdio.h>

#include "../include/chessboard.h"
#include "../include/clear.h"
#include "../include/definition.h"

void rendering_chessboard(Chessboard *chessboard, bool eated_food)
{
    chessboard->board[chessboard->head.x][chessboard->head.y] = SNAKE_BODY;

    if (eated_food)
    {
        chessboard->board[chessboard->food.x][chessboard->food.y] = FOOD;
    }
    else
    {
        chessboard->board[chessboard->tail.x][chessboard->tail.y] = SPACE;
    }
}

void print_chessboard(const Chessboard *const chessboard)
{
    size_t x = 0;

    clear_stdio();
    clear_screen();

    for (x = 0; x < CHESSBOARD_SIZE_X; x = x + 1)
    {
        printf_s("%s\n", chessboard->board[x]);
    }
}
