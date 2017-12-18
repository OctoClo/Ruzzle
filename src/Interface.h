#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL2/SDL.h>

#include "Grid.h"
#include "Timer.h"
#include "CurrentWord.h"
#include "Score.h"
#include "Button.h"
#include "Letter.h"
#include "Dictionnary.h"

typedef struct _timer Timer;
typedef struct _score Score;
typedef struct _currentWord CurrentWord;
typedef struct _grid Grid;
typedef struct _button Button;

typedef struct _interface
{
    Timer* timer;
    Score* score;

    CurrentWord* currentWord;
    Grid* grid;

    Button* buttonEnd;
    Button* buttonQuit;
} Interface;

Interface* createInterface(void);

void handleClick(Interface*, SDL_Event*);
void handleAddLetter(Interface*, Letter*);
int isValidLetter(Interface*, Letter*);
void handleFinishWord(Interface*);
int isValidWord(Interface*, Word*);

void updateInterface(Interface*);
void renderInterface(Interface*, SDL_Renderer*);

void freeInterface(Interface*);

#endif // INTERFACE_H
