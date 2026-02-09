#include <stdbool.h>
#include <stdio.h>

#include <conio.h>

#include "../include/clear.h"
#include "../include/color.h"
#include "../include/definition.h"
#include "../include/menu.h"
#include "../include/settings.h"

char *menu_text[MENU_ITEMS_NUMBER] = {
    "Welcome to play XINCHENG's snake game.\n", "Let's go!\n",
    "game difficulty: ◀ %u ▶\n", "Looking forward to our next encounter.\n"};
Settings settings;
uint8_t now_choice;

void print_menu()
{
    clear_stdio();
    clear_screen();

    size_t i = 0;
    for (i = 0; i < MENU_ITEMS_NUMBER; i = i + 1)
    {
        if (i == now_choice)
        {
            print_colorfully(BLACK, WHITE, menu_text[i]);
        }
        else
        {
            printf_s(menu_text[i]);
        }
    }
}

void menu()
{
    settings.difficulty = 5;
    now_choice = 0;

    print_menu();

    while (true)
    {
        ANSI input = EXTENSION_CODE;
        input = getch();

        if (input == EXTENSION_CODE)
        {
            input = getch();

            switch (input)
            {
            case UP:
                now_choice = (now_choice - 1) % MENU_ITEMS_NUMBER;
                break;
            case DOWN:
                now_choice = (now_choice + 1) % MENU_ITEMS_NUMBER;
                break;
            case LEFT:
                if (now_choice == GAME_DIFFICULITY)
                {
                    settings.difficulty = (settings.difficulty - 1) % 10 + 1;
                }
                break;
            case RIGHT:
                if (now_choice == GAME_DIFFICULITY)
                {
                    settings.difficulty = (settings.difficulty + 1) % 10 + 1;
                }
                break;
            case QUIT:
                break;
            case ENTER:
                break;
            case EXTENSION_CODE:
                break;
            }

            print_menu();
        }
        else if (input == ENTER)
        {
            switch (now_choice)
            {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                return;
                break;
            }
        }
        else if (input == QUIT)
        {
            return;
        }
    }
}
