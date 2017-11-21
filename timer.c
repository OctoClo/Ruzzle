#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "timer.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("Error during SDL initialization : %s\n", SDL_GetError());

    int tempsPrecedent = 0, tempsActuel = 0;


    while(tempsActuel<=60000)
    {
        printf("temps: %d sec\n",tempsActuel/1000);
        Sleep(1000);
        tempsActuel = SDL_GetTicks();
    }


}




