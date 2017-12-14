#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED

#include <SDL2/SDL.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Texture.h"
#include "GameManager.h"
#include "Enums.h"

typedef struct Letter Letter;

struct Letter
{
    char character;
    int weight;
    Modifier modif;
    Texture* tile;
    Texture* bonus;
    int selected;
    Texture* selectedTile;
    int x, y;
} Letter;
};

Letter* createLetter(GameManager*, char, int, int);
Letter* createLetterModif(GameManager*, char, int, int, Modifier);

int scoreLetter(Letter*);
void renderLetter(Letter*, SDL_Renderer*);

void freeLetter(Letter*);


#endif // LETTER_H_INCLUDED
