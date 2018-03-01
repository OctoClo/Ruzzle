#include "InterfaceGame.h"

InterfaceGame* createInterfaceGame(void)
{
    InterfaceGame* interfaceGame = malloc(sizeof(InterfaceGame));

    interfaceGame->timer = createTimer();
    interfaceGame->score = createScore();

    interfaceGame->currentWord = createCurrentWord();
    interfaceGame->grid = createGrid();

    interfaceGame->buttonEnd = createButton("./resources/assets/buttons/game/button_end.png", 75, 600);
    interfaceGame->buttonQuit = createButton("./resources/assets/buttons/game/button_quit.png", 275, 600);

    return interfaceGame;
}

void handleClickInterfaceGame(InterfaceGame* interfaceGame, SDL_Event* e)
{
    if (e->button.button == SDL_BUTTON_LEFT)
    {
        Letter* letter = getLetterCoord(gameManager->interfaceGame->grid, e->button.x, e->button.y);
        if (letter != NULL)
            handleAddLetter(gameManager->interfaceGame, letter);
        else if (isClickedButton(interfaceGame->buttonEnd, e->button.x, e->button.y) == 1)
            setStep(END);
        else if (isClickedButton(interfaceGame->buttonQuit, e->button.x, e->button.y) == 1)
            setStep(QUIT);
    }
    else if (e->button.button == SDL_BUTTON_RIGHT)
        handleFinishWord(gameManager->interfaceGame);
}

void handleAddLetter(InterfaceGame* interfaceGame, Letter* letter)
{
    if ( !isEmptyWord(interfaceGame->currentWord->word) && !isValidLetter(interfaceGame, letter))
        return;

    addLetter(interfaceGame->currentWord, letter);
    setSelectedLetter(letter, 1);
}

int isValidLetter(InterfaceGame* interfaceGame, Letter* letter)
{
    return (isValidLetterGrid(interfaceGame->grid,
                              getLetter(interfaceGame->currentWord->word, sizeWord(interfaceGame->currentWord->word)),
                              letter) == 1) ? 1 : 0;
}

void handleFinishWord(InterfaceGame* interfaceGame)
{
    if ( !isEmptyWord(interfaceGame->currentWord->word) && isValidWord(interfaceGame, interfaceGame->currentWord->word))
    {
        addWord(interfaceGame->currentWord->word);
        addWordToScore(interfaceGame->score, interfaceGame->currentWord->word);
        setScore(interfaceGame->currentWord->word, scoreWord(interfaceGame->currentWord->word));
    }
    finishWord(interfaceGame->currentWord);
    unselectAllLetters(interfaceGame->grid);
}

int isValidWord(InterfaceGame* interfaceGame, Word* word)
{
    return (!isWordAlreadyFound(word) && searchNode(gameManager->dictionary, getWord(word))) ? 1 : 0;
}

void updateInterfaceGame(InterfaceGame* interfaceGame)
{
    updateTimer(interfaceGame->timer);
    updateScore(interfaceGame->score);

    updateCurrentWord(interfaceGame->currentWord);
}

void renderInterfaceGame(InterfaceGame* interfaceGame, SDL_Renderer* renderer)
{
    renderTimer(interfaceGame->timer, renderer);
    renderScore(interfaceGame->score, renderer);

    renderCurrentWord(interfaceGame->currentWord, renderer);
    renderGrid(interfaceGame->grid, renderer);

    renderButton(interfaceGame->buttonEnd, renderer);
    renderButton(interfaceGame->buttonQuit, renderer);
}

void freeInterfaceGame(InterfaceGame* interfaceGame)
{
    freeButton(interfaceGame->buttonQuit);
    freeButton(interfaceGame->buttonEnd);

    freeGrid(interfaceGame->grid);
    freeCurrentWord(interfaceGame->currentWord);

    freeScore(interfaceGame->score);
    freeTimer(interfaceGame->timer);

    free(interfaceGame);
    interfaceGame = NULL;
}
