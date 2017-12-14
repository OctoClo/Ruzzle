#include "timer.h"


Timer* createTimer(GameManager* gameManager)
{
    Timer* timer = malloc(sizeof(Timer));
    timer->timerTexture = malloc(sizeof(timer->timerTexture));

    const char* fontPath = "./resources/fonts/Symtext.ttf";
    timer->timerFont = TTF_OpenFont(fontPath, 32);
    if (timer->timerFont == NULL)
        fatalError(gameManager, "Error during font loading", "TTF");

    timer->time = 0, timer->currentTime = 0, timer->startTime = 0;
    timer->startTime = SDL_GetTicks();

    return timer;
}

void updateTimer(Timer* timer, GameManager* gameManager)
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
        fatalError(gameManager, "Error during timer texture creation", "TTF");
    timer->timerText[0] = '\0';
}

void renderTimer(Timer* timer, SDL_Renderer* renderer)
{
    renderTexture(timer->timerTexture, 50, 50, renderer);
}

void freeTimer(Timer* timer)
{
    freeTexture(timer->timerTexture);
    TTF_CloseFont(timer->timerFont);
}

/*int temps = 0, tempsActuel = 0, tempsDepart = 0;
tempsDepart = SDL_GetTicks();

while(temps<=120){

     //printf("depart : %d, temps : %d, tempsActuel : %d\n",tempsDepart/1000,temps,tempsActuel/1000);
     if(temps==0){
        printf("2:00\n");
     }
     else if(temps<=50){
        printf("1:%d\n",60-temps);
     }
     else if(temps>60&&temps<=110){
        printf("0:%d\n",120-temps);
     }
     else{
        if(temps>50 && temps<60){
             printf("1:0%d\n",60-temps);
        }
        else{
            printf("0:0%d\n",120-temps);
        }

     }
     Sleep(1000);
     tempsActuel = SDL_GetTicks();
     temps=(tempsActuel/1000)-(tempsDepart/1000);
}*/





