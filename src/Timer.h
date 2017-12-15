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
    Texture* texture;
    TTF_Font* font;
    SDL_Color color;
    int x, y;
    char text[20];

    int time;
    int currentTime;
    int startTime;
} Timer;

Timer* createTimer(void);

void updateTimer(Timer*);
void renderTimer(Timer*, SDL_Renderer*);

void freeTimer(Timer*);

#endif
