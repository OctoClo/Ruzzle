#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "string.h"

#include "Texture.h"
#include "Enums.h"

struct Grid;

typedef struct
{
    Step step;
    SDL_Window* window;
    SDL_Renderer* renderer;
    struct Grid* grid;
} GameManager;

GameManager* createGameManager();
void gameLoop(GameManager*);
void freeGameManager(GameManager*);
void cleanExit();

void handleEvents(GameManager*, SDL_Event*);
void update(GameManager*);
void render(GameManager*);

void fatalError(GameManager*, const char*, const char*);

#endif // GAME_MANAGER_H
