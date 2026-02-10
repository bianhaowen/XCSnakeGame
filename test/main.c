#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include <conio.h>
#include <windows.h>

#include "../include/clear.h"
#include "../include/color.h"
#include "../include/menu.h"

// void test1(Color a, char *b, ...)
// {
//     va_list ap;
//     va_start(ap, b);
//     set_text_color(a);
//     vprintf(b, ap);
//     set_text_color(WHITE);
//     va_end(ap);
//     printf("!\n");
// }

int main()
{
    system("chcp 65001");
    // clear_stdio();
    // printf("1\n");
    // char a = getch();
    // clearScreenWinAPI();
    // printf("2\n");

    // menu();

    // char choice = 0;
    // choice = getch();
    // printf("%u\n", (uint64_t)choice);
    // choice = getch();
    // printf("%u\n", (uint64_t)choice);

    // printf("This is white.\n");
    // printf("%sThis is red.\n", red_font);
    // printf("%s", white_font);
    // printf("This is white.\n");

    // int d = 1;
    // test1(RED, "%d+%d.\n", d, d + 1);

    // print_colorfully(BLACK, WHITE, "Hello Color!\n");
    // printf("Bye Bye Color!\n");

    menu();
    clear_screen();
    clear_stdio();

    return 0;
}
