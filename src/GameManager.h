#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

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

#endif // GAME_MANAGER_H
