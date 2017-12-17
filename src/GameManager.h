#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "string.h"

#include "Utils.h"
#include "Enums.h"

typedef struct _interface Interface;

typedef struct _gameManager
{
    Step step;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Interface* interfaceR;
    int wordsCount;
} GameManager;

GameManager* gameManager;

void initGameManager(void);
void initSDL(void);
void gameLoop(void);

void handleEvents(SDL_Event*);
void update(void);
void render(void);

void freeGameManager(void);
void cleanExit(void);

void fatalError(const char*, const char*);

#endif // GAME_MANAGER_H
