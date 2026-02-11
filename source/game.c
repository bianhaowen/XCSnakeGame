#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <Windows.h>
#include <conio.h>

#include "../include/chessboard.h"
#include "../include/clear.h"
#include "../include/definition.h"
#include "../include/game.h"
#include "../include/settings.h"
#include "../include/snake.h"

static Chessboard chessboard;
static Snake snake;

Coordinates generate_food()
{
    srand((unsigned int)time(NULL));

    Coordinates food;
    food.x = rand() % CHESSBOARD_SIZE_X;
    food.y = rand() % CHESSBOARD_SIZE_Y;

    while (chessboard.board[food.x][food.y] == SNAKE_BODY ||
           chessboard.board[food.x][food.y] == '-' ||
           chessboard.board[food.x][food.y] == '-')
    {
        food.x = (food.x + 1) % CHESSBOARD_SIZE_X;
        food.y = (food.y + 1) % CHESSBOARD_SIZE_Y;
    }

    return food;
}

bool eat_food(Coordinates *new_head)
{
    if (new_head->x == chessboard.food.x && new_head->y == chessboard.food.y)
    {
        return true;
    }

    return false;
}

bool eat_self(Coordinates *new_head)
{
    if (chessboard.board[new_head->x][new_head->y] == SNAKE_BODY)
    {
        return true;
    }

    return false;
}

GameResult game(const Settings *const settings)
{
    Coordinates new_head;
    bool eated_food = false;
    Coordinates food;
    ANSI input = EXTENSION_CODE;
    size_t i = 0;
    GameResult result = GAME_CONTINUE;

    chessboard.head.x = CHESSBOARD_SIZE_X / 2;
    chessboard.head.y = CHESSBOARD_SIZE_Y / 2;
    chessboard.tail.x = CHESSBOARD_SIZE_X / 2;
    chessboard.tail.y = CHESSBOARD_SIZE_Y / 2 + BORN_LENGTH - 1;
    memset(chessboard.board, SPACE,
           sizeof(char) * CHESSBOARD_SIZE_X * CHESSBOARD_SIZE_Y);

    for (i = 0; i < CHESSBOARD_SIZE_X; ++i)
    {
        chessboard.board[i][CHESSBOARD_SIZE_Y - 1] = '\0';
    }

    for (i = 0; i < CHESSBOARD_SIZE_X; ++i)
    {
        chessboard.board[i][0] = '|';
        chessboard.board[i][CHESSBOARD_SIZE_Y - 2] = '|';
    }

    for (i = 0; i < CHESSBOARD_SIZE_Y - 1; ++i)
    {
        chessboard.board[0][i] = '-';
        chessboard.board[CHESSBOARD_SIZE_X - 1][i] = '-';
    }

    for (i = 0; i < BORN_LENGTH; ++i)
    {
        chessboard.board[CHESSBOARD_SIZE_X / 2][CHESSBOARD_SIZE_Y / 2 + i] =
            SNAKE_BODY;
    }

    chessboard.food = generate_food();
    chessboard.board[chessboard.food.x][chessboard.food.y] = EXCLAMATION;

    snake.head = BORN_LENGTH - 1;
    snake.tail = 0;
    snake.length = BORN_LENGTH;
    snake.orientation = LEFT;
    memset(snake.body, 0, sizeof(Coordinates) * MAXIMUM_LENGTH);

    for (i = 0; i < BORN_LENGTH; ++i)
    {
        snake.body[i].x = CHESSBOARD_SIZE_X / 2;
        snake.body[i].y = CHESSBOARD_SIZE_Y / 2 + BORN_LENGTH - 1 - i;
    }

    while (true)
    {
        input = snake.orientation;
        eated_food = false;
        print_chessboard(&chessboard);
        printf_s("score: %llu\n", snake.length - BORN_LENGTH);

        if (kbhit())
        {
            input = getch();

            if (input == EXTENSION_CODE)
            {
                input = getch();
            }
            else if (input == QUIT)
            {
                return GAME_TERMINATION;
            }
            else if (input == Q_LOWERCASE || input == Q)
            {
                return GAME_TERMINATION;
            }
        }

        // printf("Snake orientation: %u\n", snake.orientation);
        // printf("input orientation: %u\n", input);
        new_head = new_snake_head(&snake, input);
        // printf("Snake head: [%u, %u]\n", snake.body[snake.head].x,
        //        snake.body[snake.head].y);
        // printf("New head: [%u, %u]\n", new_head.x, new_head.y);

        if (eat_self(&new_head))
        {
            return GAME_OVER;
        }
        else if (eat_food(&new_head))
        {
            if (snake.length == BORN_LENGTH + MAXIMUM_LENGTH)
            {
                return GAME_WIN;
            }

            snake.length = snake.length + 1;
            eated_food = true;
            chessboard.food = generate_food();
        }

        move_forward(&snake, &new_head, eated_food);
        chessboard.head = snake.body[snake.head];
        rendering_chessboard(&chessboard, eated_food);
        chessboard.tail = snake.body[snake.tail];
        Sleep(HUNDRED_MILLISECOND * (11 - settings->difficulty));
    }

    return GAME_WIN;
}
