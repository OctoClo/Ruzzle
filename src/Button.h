#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

#include "Texture.h"
#include "GameManager.h"

typedef struct _button
{
    Texture* tile;
    int x, y;
} Button;

Button* createButton(char*, int, int);

int isClickedButton(Button*, int, int);

void renderButton(Button*, SDL_Renderer*);

void freeButton(Button*);

#endif // BUTTON_H
