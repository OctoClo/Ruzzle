#include "GameManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
#include "word.h"
#include "LinkedLetter.h"
#include "Dictionnary.h"

#define TAILLE_MAX 100

GameManager* createGameManager()
{
    // Declare which function to call on program exit
    atexit(cleanExit);

    GameManager* gameManager = malloc(sizeof(GameManager));

    // Initialize struct values
    gameManager->window = malloc(sizeof gameManager->window);
    gameManager->renderer = malloc(sizeof gameManager->renderer);
    gameManager->step = GAME;

    // Initialize all libraries; print eventual errors
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

    // Create game window and renderer
    gameManager->window = SDL_CreateWindow("Ruzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 700, SDL_WINDOW_OPENGL);
	if (!gameManager->window)
		fatalError(gameManager, "Error during window creation", "SDL");

    gameManager->renderer = SDL_CreateRenderer(gameManager->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!gameManager->renderer)
        fatalError(gameManager, "Error during render creation", "SDL");

    gameManager->grid = createGrid(gameManager);

    //TEST FRANK

    /*FILE* dico = NULL;
    char word[TAILLE_MAX];
    Word* w = initWord();
    addLetterInWord(w, createLetter(gameManager, 'j', 0, 0));

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



        fclose(dico);
    }

    if(checkIfLetterIsPossible(root, w, createLetter(gameManager, 'a', 0, 1))){
        SDL_Log("Check");
    }else{
        SDL_Log("Not check");
    }


    //Vérification de présence du mot (Test)
    if(searchNode(root, "jambon")){
        printf("OUIIII");

    }else{
        printf("NOOON");
    }


    */
    //FIN TEST FRANK

    return gameManager;
}

void gameLoop(GameManager* gameManager)
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

void freeGameManager(GameManager* gameManager)
{
    freeGrid(gameManager->grid);
    free(gameManager->grid);
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

void cleanExit()
{
    // Quit every library that has been initialized
    IMG_Quit();
    if (TTF_WasInit())
        TTF_Quit();
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

void handleEvents(GameManager* gameManager, SDL_Event* e)
{
    // Handle quit event
    if (e->type == SDL_QUIT)
        gameManager->step = QUIT;
    else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
        gameManager->step = QUIT;
}

void update(GameManager* gameManager)
{
    // Update things
}

void render(GameManager* gameManager)
{
    // Clear screen with black color
    SDL_SetRenderDrawColor(gameManager->renderer, 0x22, 0x9E, 0x8F, 0x00);
    SDL_RenderClear(gameManager->renderer);

    // Render things
    renderGrid(gameManager->grid, gameManager->renderer);

    SDL_RenderPresent(gameManager->renderer);
}

void fatalError(GameManager* gameManager, const char* error, const char* library)
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

    freeGameManager(gameManager);
    exit(EXIT_FAILURE);
}
