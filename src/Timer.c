#include "timer.h"


Timer* createTimer(void)
{
    Timer* timer = malloc(sizeof(Timer));
    timer->timerTexture = malloc(sizeof(timer->timerTexture));

    timer->timerFont = TTF_OpenFont(FONT_PATH, 32);
    if (timer->timerFont == NULL)
        fatalError("Error during font loading", "TTF");
    timer->x = BEGIN_GRID_X + PIXELS_TO_CENTER_LETTER;
    timer->y = 50;

    timer->time = 0, timer->currentTime = 0, timer->startTime = 0;
    timer->startTime = SDL_GetTicks();

    return timer;
}

void updateTimer(Timer* timer)
{
    char* time[50];
    if (timer->time > 120)
    {
        strcat(timer->timerText, "0:00");
        gameManager->step = QUIT;
    }
    else
    {
        if (timer->time == 0)
            strcat(timer->timerText, "2:00");
        else if (timer->time <= 50)
        {
            sprintf(time, "1:%d", 60 - timer->time);
            strcat(timer->timerText, time);
        }
        else if (timer->time > 60 && timer->time <= 110)
        {
            sprintf(time, "0:%d", 120 - timer->time);
            strcat(timer->timerText, time);
        }
        else
        {
            if (timer->time > 50 && timer->time == 60)
                strcat(timer->timerText, "1:00");
            else if (timer->time > 50 && timer->time < 60)
            {
                sprintf(time, "1:0%d", 60 - timer->time);
                strcat(timer->timerText, time);
            }
            else
            {
                sprintf(time, "0:0%d", 120 - timer->time);
                strcat(timer->timerText, time);
            }
        }
    }

    timer->currentTime = SDL_GetTicks();
    timer->time = (timer->currentTime / 1000) - (timer->startTime / 1000);

    SDL_Color timerColor = { 255, 255, 255 };
    if (createTextTexture(timer->timerTexture, timer->timerText, &timerColor, timer->timerFont, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during timer texture creation", "TTF");
    timer->timerText[0] = '\0';
}

void renderTimer(Timer* timer, SDL_Renderer* renderer)
{
    renderTexture(timer->timerTexture, timer->x, timer->y, renderer);
}

void freeTimer(Timer* timer)
{
    freeTexture(timer->timerTexture);
    TTF_CloseFont(timer->timerFont);
}

