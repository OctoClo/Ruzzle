#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "GameManager.h"

int main(int argc, char** argv)
{
    struct GameManager gameManager = { GAME, NULL, NULL };

    initGameManager(&gameManager);
    gameLoop(&gameManager);

    cleanExitGameManager(&gameManager);
    return EXIT_SUCCESS;
}
