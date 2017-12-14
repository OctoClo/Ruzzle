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
#include "Utils.h"
#include "Word.h"

struct Grid;
struct Letter;

typedef struct GameManager GameManager;

struct GameManager
{
    Step step;
    SDL_Window* window;
    SDL_Renderer* renderer;
    struct Grid* grid;
    struct Word* currentWord;
};

GameManager* createGameManager();
void gameLoop(GameManager*);

void handleEvents(GameManager*, SDL_Event*);
void update(GameManager*);
void render(GameManager*);

void addLetter(GameManager*, struct Letter*);
void finishWord(GameManager*);

void freeGameManager(GameManager*);
void cleanExit(void);

void fatalError(GameManager*, const char*, const char*);

#endif // GAME_MANAGER_H
