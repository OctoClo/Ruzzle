#include "GameManager.h"

void initSDL(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        fatalError("Error during SDL initialization", "SDL");
    if (TTF_Init() != 0)
		fatalError("Error during SDL_ttf initialization", "TTF");

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int imageBitmask = IMG_Init(imageFlags);
	if ((imageBitmask & imageFlags) != imageFlags)
		fatalError("Error during SDL_image initialization", "IMG");
}

void readRootDictionary(void)
{
    FILE* dictionary = NULL;
    char words[MAX_NB_WORDS];

    dictionary = fopen("src/file/dico.txt", "r");
    rootDictionary = initNode();

    if (dictionary != NULL)
    {
        while(fgets(words, MAX_NB_WORDS, dictionary) != NULL)
        {
            strtok(words, "\n");
            insertNode(rootDictionary, words);
        }
        fclose(dictionary);
    }
    else
        fatalError("Error during root dictionary reading", "");
}

void initGameManager(void)
{
    gameManager = malloc(sizeof(GameManager));

    // Initialize struct values
    setStep(BEGIN);
    gameManager->hasPlayed = 0;

    // Create game window and renderer
    gameManager->window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if (!gameManager->window)
		fatalError("Error during window creation", "SDL");

    gameManager->renderer = SDL_CreateRenderer(gameManager->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gameManager->renderer)
        fatalError("Error during render creation", "SDL");

    gameManager->interfaceBegin = createInterfaceBegin();
    gameManager->interfaceGame = createInterfaceGame();

    gameManager->wordsCount = 0;
    gameManager->words = NULL;

    gameManager->dictionary = initNode();
    gameManager->dictionary = possibleWordInGrid(rootDictionary);
}

void gameLoop(void)
{
    SDL_Event event;

    // Game loop : handle every event, update and render game
    while (gameManager->step != QUIT)
    {
        if (gameManager->step == REPLAY)
        {
            freeGameManager();
            initGameManager();
        }

        while (SDL_PollEvent(&event))
            handleEvents(&event);
        update();
        render();
    }
}

void setStep(Step step)
{
    gameManager->step = step;
    if (step == GAME)
        gameManager->hasPlayed = 1;
    else if (step == END)
        gameManager->score = gameManager->interfaceGame->score->score;
}

void addWord(Word* word)
{
    gameManager->wordsCount++;
    gameManager->words = realloc(gameManager->words, (gameManager->wordsCount * sizeof(Word*)));
    gameManager->words[gameManager->wordsCount - 1] = malloc(sizeof(Word));
    gameManager->words[gameManager->wordsCount - 1] = word;
}

int isWordAlreadyFound(Word* word)
{
    if (gameManager->wordsCount > 0)
    {
        int i;
        for (i = 0 ; i < gameManager->wordsCount ; i++)
        {
            if (strcmp(getWord(gameManager->words[i]), getWord(word)) == 0)
                return 1;
        }
    }

    return 0;
}

void handleEvents(SDL_Event* e)
{
    // Handle quit event
    if (e->type == SDL_QUIT)
        setStep(QUIT);
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
        setStep(QUIT);

    // Handle mouse inputs
    else if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        if (gameManager->step == BEGIN)
            handleClickInterfaceBegin(gameManager->interfaceBegin, e);
        else if (gameManager->step == GAME)
            handleClickInterfaceGame(gameManager->interfaceGame, e);
    }
}

void update(void)
{
    // Update things
    if (gameManager->step == GAME)
        updateInterfaceGame(gameManager->interfaceGame);
}

void render(void)
{
    // Clear screen with black color
    SDL_SetRenderDrawColor(gameManager->renderer, 0x22, 0x9E, 0x8F, 0x00);
    SDL_RenderClear(gameManager->renderer);

    // Render things
    if (gameManager->step == BEGIN)
        renderInterfaceBegin(gameManager->interfaceBegin, gameManager->renderer);
    else if (gameManager->step == GAME)
        renderInterfaceGame(gameManager->interfaceGame, gameManager->renderer);

    SDL_RenderPresent(gameManager->renderer);
}

void cleanExit(void)
{
    // Quit every library that has been initialized
    IMG_Quit();
    if (TTF_WasInit())
        TTF_Quit();
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

void freeGameManager(void)
{
    freeInterfaceGame(gameManager->interfaceGame);
    freeInterfaceBegin(gameManager->interfaceBegin);

    int i;
    for (i = 0 ; i < gameManager->wordsCount ; i++)
    {
        //freeWord(gameManager->words[i]);
        free(gameManager->words[i]); // TODO inside of freeWord()
    }
    free(gameManager->words);
    gameManager->words = NULL;

    // Destroy renderer and window if created
    if (gameManager->renderer != NULL)
        SDL_DestroyRenderer(gameManager->renderer);
    gameManager->renderer = NULL;

    if (gameManager->window != NULL)
        SDL_DestroyWindow(gameManager->window);
    gameManager->window = NULL;

    free(gameManager);
    gameManager = NULL;
}

void fatalError(const char* error, const char* library)
{
    // Print error
    SDL_Log("Fatal error ! ");
    SDL_Log(error);

	// Print details
	if (strcmp(library, "SDL") == 0)
        SDL_Log(SDL_GetError());
    else if (strcmp(library, "TTF") == 0)
        SDL_Log(TTF_GetError());
    else if (strcmp(library, "IMG") == 0)
        SDL_Log(IMG_GetError());

    if (gameManager != NULL)
        freeGameManager();
    exit(EXIT_FAILURE);
}

