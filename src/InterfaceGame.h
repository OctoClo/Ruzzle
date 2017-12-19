#ifndef INTERFACE_GAME_H
#define INTERFACE_GAME_H

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

typedef struct _interfaceGame
{
    Timer* timer;
    Score* score;

    CurrentWord* currentWord;
    Grid* grid;

    Button* buttonEnd;
    Button* buttonQuit;
} InterfaceGame;

InterfaceGame* createInterfaceGame(void);

void handleClickInterfaceGame(InterfaceGame*, SDL_Event*);
void handleAddLetter(InterfaceGame*, Letter*);
int isValidLetter(InterfaceGame*, Letter*);
void handleFinishWord(InterfaceGame*);
int isValidWord(InterfaceGame*, Word*);

void updateInterfaceGame(InterfaceGame*);
void renderInterfaceGame(InterfaceGame*, SDL_Renderer*);

void freeInterfaceGame(InterfaceGame*);

#endif // INTERFACE_GAME_H
