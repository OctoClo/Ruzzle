#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 500

#define GRID_SIZE 4
#define GRID_CELL_SIZE (WINDOW_WIDTH / (GRID_SIZE + 1)) // 100
#define BEGIN_GRID_X (GRID_CELL_SIZE / 2) // 50
#define BEGIN_GRID_Y (WINDOW_HEIGHT - ((GRID_SIZE + 1) * GRID_CELL_SIZE) - (GRID_CELL_SIZE / 4)) // 175

#define LETTER_ASSET_PIXELS 80
#define PIXELS_TO_CENTER_LETTER ((GRID_CELL_SIZE - LETTER_ASSET_PIXELS) / 2) // 10

#define FONT_PATH "./resources/fonts/Symtext.ttf"

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int) 'a')
#define MAX_NB_WORDS 100

int randInter(int, int);

#endif // UTILS_H
