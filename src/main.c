#include <stdio.h>
#include <stdlib.h>

#include "GameManager.h"

int main(int argc, char** argv)
{
    GameManager* gameManager = createGameManager();
    gameLoop(gameManager);

    freeGameManager(gameManager);
    free(gameManager);

    return EXIT_SUCCESS;
}
