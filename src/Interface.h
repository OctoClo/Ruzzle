#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL2/SDL.h>

#include "Grid.h"
#include "Timer.h"
#include "Letter.h"

typedef struct _interface
{
    Grid* grid;
    Timer* timer;
} Interface;

Interface* createInterface(void);

void handleClick(Interface*, SDL_Event*);
void handleFinishWord(Interface*);

void updateInterface(Interface*);
void renderInterface(Interface*, SDL_Renderer*);

void freeInterface(Interface*);

#endif // INTERFACE_H
