#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED

#include <SDL2/SDL.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Enums.h"
#include "Texture.h"
#include "GameManager.h"

typedef struct _letter
{
    Texture* tile;
    Texture* bonus;
    Texture* selectedTile;
    int x, y;

    char character;
    int weight;
    Modifier modif;
    int selected;
} Letter;

Letter* createLetter(char, int, int, Modifier);

int scoreLetter(Letter*);
void setSelectedLetter(Letter*, int);

void renderLetter(Letter*, SDL_Renderer*);

void freeLetter(Letter*);

#endif // LETTER_H_INCLUDED
