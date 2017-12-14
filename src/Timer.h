#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Texture.h"
#include "GameManager.h"

typedef struct Timer Timer;
struct Timer
{
    Texture* timerTexture;
    TTF_Font* timerFont;
    SDL_Color timerColor;
    char timerText[20];
    int time;
    int currentTime;
    int startTime;
};

Timer* createTimer(GameManager*);

void updateTimer(Timer*, GameManager*);
void renderTimer(Timer*, SDL_Renderer*);

void freeTimer(Timer*);

#endif
