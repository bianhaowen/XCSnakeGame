#include <conio.h>
#include <stdbool.h>

#include "../include/coordinates.h"
#include "../include/snake.h"

void move_forward(Snake *snake, Coordinates *new_head, bool eated_food)
{
    snake->head = (snake->head + 1) % MAXIMUM_LENGTH;
    snake->body[snake->head] = *new_head;

    if (!eated_food)
    {
        snake->tail = (snake->tail + 1) % MAXIMUM_LENGTH;
    }
}

void steering(Snake *snake, const ANSI orientation)
{
    if (snake->orientation != orientation &&
        snake->orientation + orientation != UP + DOWN)
    {
        snake->orientation = orientation;
    }
}

Coordinates new_snake_head(Snake *snake, const ANSI input)
{
    Coordinates new_head = snake->body[snake->head];
    steering(snake, input);

    switch (snake->orientation)
    {
    case UP:
        if (new_head.x == 1)
        {
            new_head.x = CHESSBOARD_SIZE_X - 2;
        }
        else
        {
            new_head.x = new_head.x - 1;
        }
        break;
    case DOWN:
        if (new_head.x == CHESSBOARD_SIZE_X - 2)
        {
            new_head.x = 1;
        }
        else
        {
            new_head.x = new_head.x + 1;
        }
        break;
    case LEFT:
        if (new_head.y == 1)
        {
            new_head.y = CHESSBOARD_SIZE_Y - 3;
        }
        else
        {
            new_head.y = new_head.y - 1;
        }
        break;
    case RIGHT:
        if (new_head.y == CHESSBOARD_SIZE_Y - 3)
        {
            new_head.y = 1;
        }
        else
        {
            new_head.y = new_head.y + 1;
        }
        break;
    default:
        break;
    }

    return new_head;
}
