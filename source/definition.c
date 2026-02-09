#include <stdint.h>

#include "../include/definition.h"

// const uint64_t EXTENSION_CODE = 0xFFFFFFE0;
// const uint8_t UP = 72;
// const uint8_t DOWN = 80;
// const uint8_t LEFT = 75;
// const uint8_t RIGHT = 77;

const char black_text[] = "\x1B[30m";
const char red_text[] = "\x1B[31m";
const char green_text[] = "\x1B[32m";
const char yellow_text[] = "\x1B[33m";
const char blue_text[] = "\x1B[34m";
const char perple_text[] = "\x1B[35m";
const char cyan_text[] = "\x1B[36m";
const char white_text[] = "\x1B[37m";

const char *text_colors[] = {black_text, red_text,    green_text, yellow_text,
                             blue_text,  perple_text, cyan_text,  white_text};

const char black_background[] = "\x1B[40m";
const char red_background[] = "\x1B[41m";
const char green_background[] = "\x1B[42m";
const char yellow_background[] = "\x1B[43m";
const char blue_background[] = "\x1B[44m";
const char perple_background[] = "\x1B[45m";
const char cyan_background[] = "\x1B[46m";
const char white_background[] = "\x1B[47m";

const char *background_colors[] = {
    black_background, red_background,    green_background, yellow_background,
    blue_background,  perple_background, cyan_background,  white_background};
