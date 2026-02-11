#ifndef __GAME_H__
#define __GAME_H__

#include <stdbool.h>

#include "../include/chessboard.h"
#include "../include/coordinates.h"
#include "../include/settings.h"
#include "../include/snake.h"

typedef enum GameResult
{
    GAME_CONTINUE = 0,
    GAME_WIN = 1,
    GAME_OVER = 2,
    GAME_TERMINATION = 3

} GameResult;

Coordinates generate_food();
bool eat_food(Coordinates *new_head);
bool eat_self(Coordinates *new_head);
GameResult game(const Settings *const settings);

#endif
