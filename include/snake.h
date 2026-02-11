#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdint.h>

#include "../include/coordinates.h"
#include "../include/definition.h"
#include "../include/game.h"

#define BORN_LENGTH (size_t)5
#define MAXIMUM_LENGTH (size_t)64

typedef struct Snake
{
    uint32_t length;
    ANSI orientation;
    size_t head;
    size_t tail;
    Coordinates body[MAXIMUM_LENGTH];
} Snake;

void move_forward(Snake *snake, Coordinates *new_head, bool eated_food);
void steering(Snake *snake, const ANSI orientation);
Coordinates new_snake_head(Snake *snake, const ANSI input);

#endif
