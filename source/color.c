#include <stdarg.h>
#include <stdio.h>

#include "../include/color.h"
#include "../include/definition.h"

void set_text_color(Color text_color)
{
    printf("%s", text_colors[text_color]);
}

void set_background_color(Color background_color)
{
    printf("%s", background_colors[background_color]);
}

void print_text_colorfully(Color text_color, char *text, ...)
{
    va_list arguments;
    va_start(arguments, text);
    set_text_color(text_color);
    vprintf(text, arguments);
    set_text_color(WHITE);
    va_end(arguments);
}

void print_background_colorfully(Color background_color, char *text, ...)
{
    va_list arguments;
    va_start(arguments, text);
    set_background_color(background_color);
    vprintf(text, arguments);
    set_background_color(BLACK);
    va_end(arguments);
}

void print_colorfully(Color text_color, Color background_color, char *text, ...)
{
    va_list arguments;
    va_start(arguments, text);
    set_background_color(background_color);
    set_text_color(text_color);
    vprintf(text, arguments);
    set_text_color(WHITE);
    set_background_color(BLACK);
    va_end(arguments);
}
