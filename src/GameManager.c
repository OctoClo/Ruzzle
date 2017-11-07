#include "GameManager.h"

void initGameManager(struct GameManager* gameManager)
{
    atexit(cleanExit);

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printf("Error during SDL initialization : %s\n", SDL_GetError());

    gameManager->window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	if (!gameManager->window)
		printf("Error during window creation : %s\n", SDL_GetError());

    gameManager->renderer = SDL_CreateRenderer(gameManager->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gameManager->renderer)
        printf("Error during render creation : %s\n", SDL_GetError());
}

void gameLoop(struct GameManager* gameManager)
{
    SDL_Event event;

    while (gameManager->step != QUIT)
    {
        while (SDL_PollEvent(&event))
            handleEvents(gameManager, &event);
        update(gameManager);
        render(gameManager);
    }
}

void cleanExitGameManager(struct GameManager* gameManager)
{
    SDL_DestroyRenderer(gameManager->renderer);
    gameManager->renderer = NULL;
    SDL_DestroyWindow(gameManager->window);
	gameManager->window = NULL;
}

void cleanExit()
{
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

void handleEvents(struct GameManager* gameManager, SDL_Event* e)
{
    if (e->type == SDL_QUIT)
        gameManager->step = QUIT;
}

void update(struct GameManager* gameManager)
{
    // Mettre a jour des truuucs
}

void render(struct GameManager* gameManager)
{
    SDL_SetRenderDrawColor(gameManager->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gameManager->renderer);

    // Afficher des truuuucs

    SDL_RenderPresent(gameManager->renderer);
}
