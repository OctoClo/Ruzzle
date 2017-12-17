#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "timer.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("Error during SDL initialization : %s\n", SDL_GetError());

    int temps = 0, tempsActuel = 0, tempsDepart = 0;
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
    }



}




