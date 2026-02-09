#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdint.h>

#include "../include/coordinates.h"
#include "../include/orientation.h"

typedef struct Snake
{
    Coordinates head;
    Coordinates tail;
    uint32_t length;
    Orientation orientation;
} Snake;

#endif
