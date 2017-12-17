#ifndef CURRENT_WORD_H
#define CURRENT_WORD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Utils.h"
#include "Word.h"
#include "Letter.h"
#include "Texture.h"
#include "GameManager.h"

typedef struct _currentWord
{
    Texture* texture;
    TTF_Font* font;
    int x, y;
    char text[20];

    Word* word;
} CurrentWord;

CurrentWord* createCurrentWord(void);

void addLetter(CurrentWord*, Letter*);
void finishWord(CurrentWord*);

void updateCurrentWord(CurrentWord*);
void renderCurrentWord(CurrentWord*, SDL_Renderer*);

void freeCurrentWord(CurrentWord*);

#endif // CURRENT_WORD_H
