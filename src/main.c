#include <stdio.h>
#include <stdlib.h>

#include "GameManager.h"

int main(int argc, char** argv)
{
    // Declare which function to call on program exit
    atexit(cleanExit);

    // Initialize SDL and launch game manager
    initSDL();
    initGameManager();
    gameLoop();

    // Free every pointer
    freeGameManager();
    free(gameManager);

    return EXIT_SUCCESS;
}
