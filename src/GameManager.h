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

typedef enum Step Step;
enum Step { GAME, QUIT };

typedef struct GameManager GameManager;
struct GameManager
{
    Step step;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Texture* letter;
};

void initGameManager(GameManager*);
void gameLoop(GameManager*);
void freeGameManager(GameManager*);
void cleanExit();

void handleEvents(GameManager*, SDL_Event*);
void update(GameManager*);
void render(GameManager*);

void fatalError(GameManager*, const char*, const char*);

#endif // GAME_MANAGER_H
