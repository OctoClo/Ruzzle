#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

void handleEvents(SDL_Event*);
void update();
void render(SDL_Renderer*);

enum Step { GAME, QUIT };
enum Step step;

SDL_Renderer* renderer;

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("Error during SDL initialization : %s\n", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	if (!window)
		printf("Error during window creation : %s\n", SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
        printf("Error during render creation : %s\n", SDL_GetError());

    SDL_Event event;
    step = GAME;

    while (step != QUIT)
    {
        while (SDL_PollEvent(&event))
            handleEvents(&event);
        update();
        render(renderer);
    }

    return EXIT_SUCCESS;
}

void handleEvents(SDL_Event* e)
{
    if (e->type == SDL_QUIT)
        step = QUIT;
}

void update()
{
    // Mettre à jour des truuucs
}

void render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);

    // Afficher des truuuucs

    SDL_RenderPresent(renderer);
}
