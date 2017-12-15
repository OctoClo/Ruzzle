#include "Interface.h"

Interface* createInterface(void)
{
    Interface* interfaceR = malloc(sizeof(Interface));

    interfaceR->timer = createTimer();
    interfaceR->grid = createGrid();

    return interfaceR;
}

void handleClick(Interface* interfaceR, SDL_Event* e)
{
    if (e->button.button == SDL_BUTTON_LEFT)
    {
        Letter* letter = getLetterCoord(gameManager->interfaceR->grid, e->button.x, e->button.y);
        if (letter != NULL)
            addLetter(letter);
    }
    else if (e->button.button == SDL_BUTTON_RIGHT)
        finishWord();
}

void handleFinishWord(Interface* interfaceR)
{
    unselectAllLetters(interfaceR->grid);
}

void updateInterface(Interface* interfaceR)
{
    updateTimer(interfaceR->timer);
}

void renderInterface(Interface* interfaceR, SDL_Renderer* renderer)
{
    renderGrid(interfaceR->grid, renderer);
    renderTimer(interfaceR->timer, renderer);
}

void freeInterface(Interface* interfaceR)
{
    freeTimer(interfaceR->timer);
    free(interfaceR->timer);

    freeGrid(interfaceR->grid);
    free(interfaceR->grid);
}
