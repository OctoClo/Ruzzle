#include "GameManager.h"

void initGameManager(struct GameManager* gameManager)
{
    // Declare which function to call on program exit
    atexit(cleanExit);

    /* Initialize all libraries; print eventual errors */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        fatalError(gameManager, "Error during SDL initialization", "SDL");

    if (TTF_Init() != 0)
		fatalError(gameManager, "Error during SDL_ttf initialization", "TTF");

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imageBitmask = IMG_Init(imageFlags);
	if ((imageBitmask & imageFlags) != imageFlags)
		fatalError(gameManager, "Error during SDL_image initialization", "IMG");

	/*if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        fatalError("Warning : Linear texture filtering not enabled !", "SDL");*/

    /* Create game window and renderer */
    gameManager->window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	if (!gameManager->window)
		fatalError(gameManager, "Error during window creation", "SDL");

    gameManager->renderer = SDL_CreateRenderer(gameManager->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gameManager->renderer)
        fatalError(gameManager, "Error during render creation", "SDL");
}

void gameLoop(struct GameManager* gameManager)
{
    SDL_Event event;

    // Game loop : handle every event, update and render game
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
    /* Destroy renderer and window if created */
    if (gameManager->renderer != NULL)
    {
        SDL_DestroyRenderer(gameManager->renderer);
        gameManager->renderer = NULL;
    }
    if (gameManager->window != NULL)
    {
        SDL_DestroyWindow(gameManager->window);
        gameManager->window = NULL;
    }
}

void cleanExit()
{
    /* Quit every library that has been initialized */
    IMG_Quit();
    if (TTF_WasInit())
        TTF_Quit();
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

void handleEvents(struct GameManager* gameManager, SDL_Event* e)
{
    // Handle quit event
    if (e->type == SDL_QUIT)
        gameManager->step = QUIT;
}

void update(struct GameManager* gameManager)
{
    // Update things
}

void render(struct GameManager* gameManager)
{
    // Clear screen with black color
    SDL_SetRenderDrawColor(gameManager->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gameManager->renderer);

    // Render things

    SDL_RenderPresent(gameManager->renderer);
}

void fatalError(struct GameManager* gameManager, const char* error, const char* library)
{
    // Print error
    printf("Error : ");

	// Print details
	if (strcmp(library, "SDL") == 0)
        printf("%s\n", SDL_GetError());
    else if (strcmp(library, "TTF") == 0)
        printf("%s\n", TTF_GetError());
    else if (strcmp(library, "IMG") == 0)
        printf("%s\n", TTF_GetError());

    cleanExitGameManager(gameManager);
    exit(EXIT_FAILURE);
}