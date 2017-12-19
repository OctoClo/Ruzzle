#ifndef INTERFACE_END_H
#define INTERFACE_END_H

#include <SDL2/SDL.h>

#include "Texture.h"
#include "Button.h"

typedef struct _interfaceEnd
{
    TTF_Font* font;

    Texture* scoreLabel;
    Texture* score;
    int xScoreLabel, yScoreLabel, xScore, yScore;

    Texture* wordsCountLabel;
    Texture* wordsCount;
    int xWordsCountLabel, yWordsCountLabel, xWordsCount, yWordsCount;

    Button* buttonReplay;
    Button* buttonQuit;
} InterfaceEnd;

InterfaceEnd* createInterfaceEnd(void);

void handleClickInterfaceEnd(InterfaceEnd*, SDL_Event*);
void updateInterfaceEnd(InterfaceEnd*);
void renderInterfaceEnd(InterfaceEnd*, SDL_Renderer*);

void freeInterfaceEnd(InterfaceEnd*);

#endif // INTERFACE_END_H
