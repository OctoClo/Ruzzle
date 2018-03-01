#ifndef SCORE_H
#define SCORE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>

#include "Word.h"
#include "Texture.h"

typedef struct _word Word;

typedef struct _score
{
    Texture* texture;
    TTF_Font* font;
    int x, y;
    char text[20];

    int score;
} Score;

Score* createScore(void);

void addWordToScore(Score*, Word*);

void updateScore(Score*);
void renderScore(Score*, SDL_Renderer*);

void freeScore(Score*);

#endif // SCORE_H
