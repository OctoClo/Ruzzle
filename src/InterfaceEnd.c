#include "InterfaceEnd.h"

InterfaceEnd* createInterfaceEnd(void)
{
    InterfaceEnd* interfaceEnd = malloc(sizeof(InterfaceEnd));

    interfaceEnd->font = TTF_OpenFont(FONT_PATH, 32);
    if (interfaceEnd->font == NULL)
        fatalError("Error during font loading - Interface end", "TTF");
    SDL_Color color = { 255, 255, 255 };

    interfaceEnd->scoreLabel = malloc(sizeof(Texture));
    if (createTextTexture(interfaceEnd->scoreLabel, "Score:", &color, interfaceEnd->font, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during score label's texture creation", "IMG");
    interfaceEnd->xScoreLabel = BEGIN_GRID_X + PIXELS_TO_CENTER_LETTER;;
    interfaceEnd->yScoreLabel = 30;

    interfaceEnd->score = NULL;

    interfaceEnd->wordsCountLabel = malloc(sizeof(Texture));
    if (createTextTexture(interfaceEnd->wordsCountLabel, "Words:", &color, interfaceEnd->font, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during words count label's texture creation", "IMG");
    interfaceEnd->xWordsCountLabel = BEGIN_GRID_X + PIXELS_TO_CENTER_LETTER;;
    interfaceEnd->yWordsCountLabel = 130;

    interfaceEnd->wordsCount = NULL;

    interfaceEnd->buttonReplay = createButton("./resources/assets/buttons/end/button_replay.png", 50, 400);
    interfaceEnd->buttonQuit = createButton("./resources/assets/buttons/end/button_quit.png", 50, 550);

    return interfaceEnd;
}

void handleClickInterfaceEnd(InterfaceEnd* interfaceEnd, SDL_Event* e)
{
    if (e->button.button == SDL_BUTTON_LEFT)
    {
        if (isClickedButton(interfaceEnd->buttonReplay, e->button.x, e->button.y) == 1)
            setStep(REPLAY);
        else if (isClickedButton(interfaceEnd->buttonQuit, e->button.x, e->button.y) == 1)
            setStep(QUIT);
    }
}

void updateInterfaceEnd(InterfaceEnd* interfaceEnd)
{
    if (interfaceEnd->score == NULL)
    {
        SDL_Color color = { 255, 255, 255 };
        char text[20];

        itoa(gameManager->score, text, 10);
        interfaceEnd->score = malloc(sizeof(Texture));
        if (createTextTexture(interfaceEnd->score, text, &color, interfaceEnd->font, gameManager->renderer) == SDL_FALSE)
            fatalError("Error during score's texture creation", "IMG");
        interfaceEnd->xScore = WINDOW_WIDTH - BEGIN_GRID_X - PIXELS_TO_CENTER_LETTER - interfaceEnd->score->width;
        interfaceEnd->yScore = 30;

        itoa(gameManager->wordsCount, text, 10);
        interfaceEnd->wordsCount = malloc(sizeof(Texture));
        if (createTextTexture(interfaceEnd->wordsCount, text, &color, interfaceEnd->font, gameManager->renderer) == SDL_FALSE)
            fatalError("Error during words count's texture creation", "IMG");
        interfaceEnd->xWordsCount = WINDOW_WIDTH - BEGIN_GRID_X - PIXELS_TO_CENTER_LETTER - interfaceEnd->wordsCount->width;
        interfaceEnd->yWordsCount = 130;
    }
}

void renderInterfaceEnd(InterfaceEnd* interfaceEnd, SDL_Renderer* renderer)
{
    renderTexture(interfaceEnd->scoreLabel, interfaceEnd->xScoreLabel, interfaceEnd->yScoreLabel, renderer);
    if (interfaceEnd->score != NULL)
        renderTexture(interfaceEnd->score, interfaceEnd->xScore, interfaceEnd->yScore, renderer);
    renderTexture(interfaceEnd->wordsCountLabel, interfaceEnd->xWordsCountLabel, interfaceEnd->yWordsCountLabel, renderer);
    if (interfaceEnd->wordsCount != NULL)
        renderTexture(interfaceEnd->wordsCount, interfaceEnd->xWordsCount, interfaceEnd->yWordsCount, renderer);

    renderButton(interfaceEnd->buttonReplay, renderer);
    renderButton(interfaceEnd->buttonQuit, renderer);
}

void freeInterfaceEnd(InterfaceEnd* interfaceEnd)
{
    freeButton(interfaceEnd->buttonQuit);
    freeButton(interfaceEnd->buttonReplay);

    if (interfaceEnd->wordsCount != NULL)
        freeTexture(interfaceEnd->wordsCount);
    freeTexture(interfaceEnd->wordsCountLabel);
    if (interfaceEnd->score != NULL)
        freeTexture(interfaceEnd->score);
    freeTexture(interfaceEnd->scoreLabel);

    free(interfaceEnd);
    interfaceEnd = NULL;
}




