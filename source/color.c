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

void print_text_colorfully(Color text_color, char *text)
{
    set_text_color(text_color);
    printf("%s", text);
    set_text_color(WHITE);
}

void print_background_colorfully(Color background_color, char *text)
{
    set_background_color(background_color);
    printf("%s", text);
    set_background_color(BLACK);
}

void print_colorfully(Color text_color, Color background_color, char *text)
{
    set_background_color(background_color);
    set_text_color(text_color);
    printf("%s", text);
    set_text_color(WHITE);
    set_background_color(BLACK);
}
