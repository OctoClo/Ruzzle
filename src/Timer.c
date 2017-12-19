#include "timer.h"


Timer* createTimer(void)
{
    Timer* timer = malloc(sizeof(Timer));

    timer->texture = malloc(sizeof(Texture));

    timer->font = TTF_OpenFont(FONT_PATH, 32);
    if (timer->font == NULL)
        fatalError("Error during font loading - Timer", "TTF");

    timer->x = BEGIN_GRID_X + PIXELS_TO_CENTER_LETTER;
    timer->y = 30;

    timer->time = 0, timer->currentTime = 0, timer->startTime = 0;
    timer->startTime = SDL_GetTicks();

    return timer;
}

void updateTimer(Timer* timer)
{
    char* time[50];
    if (timer->time > 120)
    {
        strcat(timer->text, "0:00");
        gameManager->step = QUIT;
    }
    else
    {
        if (timer->time == 0)
            strcat(timer->text, "2:00");
        else if (timer->time <= 50)
        {
            sprintf(time, "1:%d", 60 - timer->time);
            strcat(timer->text, time);
        }
        else if (timer->time > 60 && timer->time <= 110)
        {
            sprintf(time, "0:%d", 120 - timer->time);
            strcat(timer->text, time);
        }
        else
        {
            if (timer->time > 50 && timer->time == 60)
                strcat(timer->text, "1:00");
            else if (timer->time > 50 && timer->time < 60)
            {
                sprintf(time, "1:0%d", 60 - timer->time);
                strcat(timer->text, time);
            }
            else
            {
                sprintf(time, "0:0%d", 120 - timer->time);
                strcat(timer->text, time);
            }
        }
    }

    timer->currentTime = SDL_GetTicks();
    timer->time = (timer->currentTime / 1000) - (timer->startTime / 1000);

    SDL_Color timerColor = { 255, 255, 255 };
    if (createTextTexture(timer->texture, timer->text, &timerColor, timer->font, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during timer texture creation", "TTF");

    timer->text[0] = '\0';
}

void renderTimer(Timer* timer, SDL_Renderer* renderer)
{
    renderTexture(timer->texture, timer->x, timer->y, renderer);
}

void freeTimer(Timer* timer)
{
    if (gameManager->hasPlayed == 1)
        freeTexture(timer->texture);

    TTF_CloseFont(timer->font);
    timer->font = NULL;

    free(timer);
    timer = NULL;
}

