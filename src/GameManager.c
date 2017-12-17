#include "GameManager.h"

#include "Dictionnary.h"


void initGameManager(void)
{
    // Declare which function to call on program exit
    atexit(cleanExit);

    gameManager = malloc(sizeof(GameManager));

    // Initialize struct values
    gameManager->window = malloc(sizeof(gameManager->window));
    gameManager->renderer = malloc(sizeof(gameManager->renderer));
    gameManager->step = GAME;

    // Initialize all libraries
    initSDL();

    // Create game window and renderer
    gameManager->window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if (!gameManager->window)
		fatalError("Error during window creation", "SDL");

    gameManager->renderer = SDL_CreateRenderer(gameManager->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gameManager->renderer)
        fatalError("Error during render creation", "SDL");


FILE* dico = NULL;
    char word[TAILLE_MAX];

    //Ouverture du fichier dico
    dico = fopen("src/file/dico.txt", "r");

    //Déclaration de l'arbre préfixé
    TrieNode* root = initNode();


    //Traitement du fichier dico
    if(dico != NULL){


        //Enregistrement des mots du dictionnaire dans l'arbre préfixée
        while(fgets(word, TAILLE_MAX, dico) != NULL){
            strtok(word, "\n");
            insertNode(root, word);
        }


        SDL_Log("Dico charger");
        fclose(dico);
    }


    //Vérification de présence du mot (Test)
    if(searchNode(root, "jambon")){
        SDL_Log("OUIIII");

    }else{
        SDL_Log("NOOON");
    }


    Word* w = initWord();

    addLetterInWord(w, createLetter('j',5 ,5 , NONE));
    addLetterInWord(w, createLetter('a',6 ,6 , NONE));

    if(checkIfLetterIsPossible(root, w, createLetter('a', 7, 7, NONE))){
        SDL_Log("Lettre possible");
    }else{
        SDL_Log("Lettre impossible");
    }





    gameManager->interfaceR = createInterface();

}

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

void gameLoop(void)
{
    SDL_Event event;

    // Game loop : handle every event, update and render game
    while (gameManager->step != QUIT)
    {
        while (SDL_PollEvent(&event))
            handleEvents(&event);
        update();
        render();
    }
}

void handleEvents(SDL_Event* e)
{
    // Handle quit event
    if (e->type == SDL_QUIT)
        gameManager->step = QUIT;
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
        gameManager->step = QUIT;

    // Handle mouse inputs
    else if (e->type == SDL_MOUSEBUTTONDOWN)
        handleClick(gameManager->interfaceR, e);
}

void update(void)
{
    // Update things
    updateInterface(gameManager->interfaceR);
}

void render(void)
{
    // Clear screen with black color
    SDL_SetRenderDrawColor(gameManager->renderer, 0x22, 0x9E, 0x8F, 0x00);
    SDL_RenderClear(gameManager->renderer);

    // Render things
    renderInterface(gameManager->interfaceR, gameManager->renderer);

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
    freeInterface(gameManager->interfaceR);

    // Destroy renderer and window if created
    if (gameManager->renderer != NULL)
    {
        SDL_DestroyRenderer(gameManager->renderer);
        free(gameManager->renderer);
    }
    if (gameManager->window != NULL)
    {
        SDL_DestroyWindow(gameManager->window);
        free(gameManager->window);
    }
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
        SDL_Log(TTF_GetError());

    freeGameManager();
    exit(EXIT_FAILURE);
}

