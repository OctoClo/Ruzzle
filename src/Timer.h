#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Utils.h"
#include "Texture.h"
#include "GameManager.h"

typedef struct _timer
{
    Texture* timerTexture;
    TTF_Font* timerFont;
    SDL_Color timerColor;
    int x, y;
    char timerText[20];

    int time;
    int currentTime;
    int startTime;
} Timer;

Timer* createTimer(void);

void updateTimer(Timer*);
void renderTimer(Timer*, SDL_Renderer*);

void freeTimer(Timer*);

#endif
