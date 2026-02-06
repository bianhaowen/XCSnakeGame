#include <stdio.h>

#include <conio.h>
#include <windows.h>

#include "../include/clear.h"

int main()
{
    system("chcp 65001");
    clear_stdio();
    printf("1\n");
    char a = getch();
    clearScreenWinAPI();
    printf("2\n");
    return 0;
}
