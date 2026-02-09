#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#include <stdint.h>

typedef enum ANSI
{
    EXTENSION_CODE = 224,
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77,
    QUIT = 3,
    ENTER = 13
} ANSI;

extern const char black_text[];
extern const char red_text[];
extern const char green_text[];
extern const char yellow_text[];
extern const char blue_text[];
extern const char perple_text[];
extern const char cyan_text[];
extern const char white_text[];

extern const char *text_colors[];

extern const char black_background[];
extern const char red_background[];
extern const char green_background[];
extern const char yellow_background[];
extern const char blue_background[];
extern const char perple_background[];
extern const char cyan_background[];
extern const char white_background[];

extern const char *background_colors[];

#endif
