#include "Interface.h"

Interface* createInterface(void)
{
    Interface* interfaceR = malloc(sizeof(Interface));

    interfaceR->timer = createTimer();
    interfaceR->score = createScore();

    interfaceR->currentWord = createCurrentWord();
    interfaceR->grid = createGrid();

    interfaceR->buttonEnd = createButton("./resources/assets/buttons/button_end.png", 75, 600);
    interfaceR->buttonQuit = createButton("./resources/assets/buttons/button_quit.png", 275, 600);

    return interfaceR;
}

void handleClick(Interface* interfaceR, SDL_Event* e)
{
    if (e->button.button == SDL_BUTTON_LEFT)
    {
        Letter* letter = getLetterCoord(gameManager->interfaceR->grid, e->button.x, e->button.y);
        if (letter != NULL)
            handleAddLetter(gameManager->interfaceR, letter);
        else if (isClickedButton(interfaceR->buttonEnd, e->button.x, e->button.y) == 1)
            gameManager->step = REPLAY;
        else if (isClickedButton(interfaceR->buttonQuit, e->button.x, e->button.y) == 1)
            gameManager->step = QUIT;
    }
    else if (e->button.button == SDL_BUTTON_RIGHT)
        handleFinishWord(gameManager->interfaceR);
}

void handleAddLetter(Interface* interfaceR, Letter* letter)
{
    if ( !isEmptyWord(interfaceR->currentWord->word) && !isValidLetter(interfaceR, letter))
        return;

    addLetter(interfaceR->currentWord, letter);
    setSelectedLetter(letter, 1);
}

int isValidLetter(Interface* interfaceR, Letter* letter)
{
    return (isValidLetterGrid(interfaceR->grid,
                              getLetter(interfaceR->currentWord->word, sizeWord(interfaceR->currentWord->word)),
                              letter) == 1) ? 1 : 0;
}

void handleFinishWord(Interface* interfaceR)
{
    if ( !isEmptyWord(interfaceR->currentWord->word) && isValidWord(interfaceR, interfaceR->currentWord->word))
    {
        addWord(interfaceR->currentWord->word);
        addWordToScore(interfaceR->score, interfaceR->currentWord->word);
    }
    finishWord(interfaceR->currentWord);
    unselectAllLetters(interfaceR->grid);
}

int isValidWord(Interface* interfaceR, Word* word)
{
    return (!isWordAlreadyFound(word) && searchNode(gameManager->dictionary, getWord(word))) ? 1 : 0;
}

void updateInterface(Interface* interfaceR)
{
    updateTimer(interfaceR->timer);
    updateScore(interfaceR->score);

    updateCurrentWord(interfaceR->currentWord);
}

void renderInterface(Interface* interfaceR, SDL_Renderer* renderer)
{
    renderTimer(interfaceR->timer, renderer);
    renderScore(interfaceR->score, renderer);

    renderCurrentWord(interfaceR->currentWord, renderer);
    renderGrid(interfaceR->grid, renderer);

    renderButton(interfaceR->buttonEnd, renderer);
    renderButton(interfaceR->buttonQuit, renderer);
}

void freeInterface(Interface* interfaceR)
{
    freeButton(interfaceR->buttonQuit);
    freeButton(interfaceR->buttonEnd);

    freeGrid(interfaceR->grid);
    freeCurrentWord(interfaceR->currentWord);

    freeScore(interfaceR->score);
    freeTimer(interfaceR->timer);

    free(interfaceR);
    interfaceR = NULL;
}
