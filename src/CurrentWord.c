#include "CurrentWord.h"

CurrentWord* createCurrentWord(void)
{
    CurrentWord* currentWord = malloc(sizeof(CurrentWord));

    currentWord->texture = malloc(sizeof(Texture));

    currentWord->font = TTF_OpenFont(FONT_PATH, 40);
    if (currentWord->font == NULL)
        fatalError("Error during font loading - CurrentWord", "TTF");

    currentWord->x = (WINDOW_WIDTH / 2);
    currentWord->y = 110;

    currentWord->word = initWord();

    return currentWord;
}

void addLetter(CurrentWord* currentWord, Letter* letter)
{
    addLetterInWord(currentWord->word, letter);
    displayWord(currentWord->word);
}

void finishWord(CurrentWord* currentWord)
{
    gameManager->wordsCount++;
    currentWord->word = initWord();
}

void updateCurrentWord(CurrentWord* currentWord)
{
    if ( !isEmptyWord(currentWord->word))
    {
        currentWord->text[0] = '\0';
        char* word = getWord(currentWord->word);
        strcat(currentWord->text, word);
        SDL_Color color = { 255, 255, 255 };
        if (createTextTexture(currentWord->texture, currentWord->text, &color, currentWord->font, gameManager->renderer) == SDL_FALSE)
            fatalError("Error during current word texture creation", "TTF");

        currentWord->text[0] = '\0';
        currentWord->x = (WINDOW_WIDTH / 2) - (currentWord->texture->width / 2);
    }
}

void renderCurrentWord(CurrentWord* currentWord, SDL_Renderer* renderer)
{
    if ( !isEmptyWord(currentWord->word))
        renderTexture(currentWord->texture, currentWord->x, currentWord->y, renderer);
}

void freeCurrentWord(CurrentWord* currentWord)
{
    if (gameManager->wordsCount > 0)
        freeTexture(currentWord->texture);

    TTF_CloseFont(currentWord->font);
    currentWord->font = NULL;

    free(currentWord);
    currentWord = NULL;
}
