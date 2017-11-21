#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include "timer.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("Error during SDL initialization : %s\n", SDL_GetError());

    int tempsPrecedent = 0, tempsActuel = 0;


    while(tempsActuel<=1000)
    {
        if(tempsActuel-tempsPrecedent==1000){
            printf("1 sec écoulée");
        }
        printf("temps: %d\n",tempsActuel);
        tempsActuel = SDL_GetTicks();
    }



}




