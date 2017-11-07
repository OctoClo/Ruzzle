#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "string.h"

enum Step { GAME, QUIT };

struct GameManager
{
    enum Step step;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

void initGameManager(struct GameManager*);
void gameLoop(struct GameManager*);
void cleanExitGameManager(struct GameManager*);
void cleanExit();

void handleEvents(struct GameManager*, SDL_Event*);
void update(struct GameManager*);
void render(struct GameManager*);

void fatalError(struct GameManager*, const char*, const char*);

#endif // GAME_MANAGER_H
