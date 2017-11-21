#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "GameManager.h"

int main(int argc, char** argv)
{
    GameManager* gameManager = malloc(sizeof(GameManager));

    initGameManager(gameManager);
    gameLoop(gameManager);

    freeGameManager(gameManager);
    free(gameManager);

    return EXIT_SUCCESS;
}
