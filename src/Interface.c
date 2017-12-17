#include "Interface.h"

Interface* createInterface(void)
{
    Interface* interfaceR = malloc(sizeof(Interface));

    interfaceR->timer = createTimer();
    interfaceR->grid = createGrid();
    interfaceR->currentWord = createCurrentWord();
    interfaceR->score = createScore();

    return interfaceR;
}

void handleClick(Interface* interfaceR, SDL_Event* e)
{
    if (e->button.button == SDL_BUTTON_LEFT)
    {
        Letter* letter = getLetterCoord(gameManager->interfaceR->grid, e->button.x, e->button.y);
        if (letter != NULL)
            handleAddLetter(gameManager->interfaceR, letter);
    }
    else if (e->button.button == SDL_BUTTON_RIGHT)
        handleFinishWord(gameManager->interfaceR);
}

void handleAddLetter(Interface* interfaceR, Letter* letter)
{
    addLetter(interfaceR->currentWord, letter);
    setSelectedLetter(letter, 1);
}

void handleFinishWord(Interface* interfaceR)
{
    if ( !isEmptyWord(interfaceR->currentWord->word))
    {
        addWord(interfaceR->currentWord->word);
        addWordToScore(interfaceR->score, interfaceR->currentWord->word);
        finishWord(interfaceR->currentWord);
        unselectAllLetters(interfaceR->grid);
    }
}

void updateInterface(Interface* interfaceR)
{
    updateTimer(interfaceR->timer);
    updateCurrentWord(interfaceR->currentWord);
    updateScore(interfaceR->score);
}

void renderInterface(Interface* interfaceR, SDL_Renderer* renderer)
{
    renderTimer(interfaceR->timer, renderer);
    renderGrid(interfaceR->grid, renderer);
    renderCurrentWord(interfaceR->currentWord, renderer);
    renderScore(interfaceR->score, renderer);
}

void freeInterface(Interface* interfaceR)
{
    freeCurrentWord(interfaceR->currentWord);
    freeGrid(interfaceR->grid);
    freeTimer(interfaceR->timer);
    freeScore(interfaceR->score);

    free(interfaceR);
    interfaceR = NULL;
}
