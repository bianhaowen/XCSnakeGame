#include <stdio.h>

#include <conio.h>
#include <windows.h>

#include "../include/clear.h"

void clear_stdio()
{
    _flushall();
}

void clear_screen()
{
    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (stdout_handle == INVALID_HANDLE_VALUE)
    {
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(stdout_handle, &csbi))
    {
        return;
    }

    DWORD count;
    DWORD cell_count = csbi.dwSize.X * csbi.dwSize.Y;
    COORD home_coords = {0, 0};

    // 填充空格和属性
    FillConsoleOutputCharacter(stdout_handle, ' ', cell_count, home_coords,
                               &count);
    FillConsoleOutputAttribute(stdout_handle, csbi.wAttributes, cell_count,
                               home_coords, &count);
    SetConsoleCursorPosition(stdout_handle, home_coords);
}
