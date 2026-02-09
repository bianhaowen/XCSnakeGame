#ifndef __COLOR_H__
#define __COLOR_H__

typedef enum Color
{
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    TELLOW = 3,
    BLUE = 4,
    PERPLE = 5,
    CYAN = 6,
    WHITE = 7
} Color;

void set_text_color(Color text_color);
void set_background_color(Color background_color);
void print_text_colorfully(Color text_color, char *text, ...);
void print_background_colorfully(Color background_color, char *text, ...);
void print_colorfully(Color text_color, Color background_color, char *text,
                      ...);

#endif
