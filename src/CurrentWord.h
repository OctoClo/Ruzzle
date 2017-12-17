#ifndef CURRENT_WORD_H
#define CURRENT_WORD_H

#include "Utils.h"
#include "Word.h"
#include "Letter.h"
#include "GameManager.h"

typedef struct _currentWord
{
    Texture* texture;
    TTF_Font* font;
    SDL_Color color;
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
