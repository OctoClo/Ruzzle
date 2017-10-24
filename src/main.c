#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("Error during SDL initialization : %s\n", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	if (!window)
		printf("Error during window creation : %s\n", SDL_GetError());

    printf("Hello world!\n");

    getchar();

    return 0;
}
