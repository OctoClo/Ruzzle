#include <stdio.h>
#include <stdlib.h>

#include "GameManager.h"

int main(int argc, char** argv)
{
    initGameManager();
    gameLoop();

    freeGameManager();
    free(gameManager);

    return EXIT_SUCCESS;
}
