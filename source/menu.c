#include <stdbool.h>
#include <stdio.h>

#include <conio.h>

#include "../include/clear.h"
#include "../include/color.h"
#include "../include/definition.h"
#include "../include/menu.h"
#include "../include/settings.h"

char title[] = "Welcome to play XINCHENG's snake game.\n";
char *menu_text[MENU_ITEMS_NUMBER] = {
    "Let's go\n", "game difficulty: ◀ %u ▶\n",
    "Looking forward to our next encounter\n"};
Settings settings;
uint8_t now_choice;

void print_menu()
{
    clear_stdio();
    clear_screen();

    printf_s(title);

    if (now_choice == 0)
    {
        print_colorfully(BLACK, WHITE, menu_text[0]);
    }
    else
    {
        printf_s(menu_text[0]);
    }

    if (now_choice == 1)
    {
        print_colorfully(BLACK, WHITE, menu_text[1], settings.difficulty);
    }
    else
    {
        printf_s(menu_text[1], settings.difficulty);
    }

    if (now_choice == 2)
    {
        print_colorfully(BLACK, WHITE, menu_text[2]);
    }
    else
    {
        printf_s(menu_text[2]);
    }
}

void menu()
{
    settings.difficulty = DEFAULT_DIFFICULTY;
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
                    if (settings.difficulty != MINIMUM_DIFFICULTY)
                    {
                        settings.difficulty = settings.difficulty - 1;
                    }
                    else
                    {
                        settings.difficulty = MAXIMUM_DIFFICULTY;
                    }
                }
                break;
            case RIGHT:
                if (now_choice == GAME_DIFFICULITY)
                {
                    if (settings.difficulty != MAXIMUM_DIFFICULTY)
                    {
                        settings.difficulty = settings.difficulty + 1;
                    }
                    else
                    {
                        settings.difficulty = MINIMUM_DIFFICULTY;
                    }
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
