#include "Score.h"

Score* createScore(void)
{
    Score* score = malloc(sizeof(Score));

    score->texture = malloc(sizeof(Texture));

    score->font = TTF_OpenFont(FONT_PATH, 32);
    if (score->font == NULL)
        fatalError("Error during font loading - Score", "TTF");

    score->x = WINDOW_WIDTH - BEGIN_GRID_X - PIXELS_TO_CENTER_LETTER;
    score->y = 30;

    score->score = 0;

    return score;
}

void addWordToScore(Score* score, Word* word)
{
    score->score += scoreWord(word);
}

void updateScore(Score* score)
{
    itoa(score->score, score->text, 10);
    SDL_Color color = { 255, 255, 255 };
    if (createTextTexture(score->texture, score->text, &color, score->font, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during score texture creation", "TTF");

    score->text[0] = '\0';
    score->x = WINDOW_WIDTH - BEGIN_GRID_X - PIXELS_TO_CENTER_LETTER - score->texture->width;
}

void renderScore(Score* score, SDL_Renderer* renderer)
{
    renderTexture(score->texture, score->x, score->y, renderer);
}

void freeScore(Score* score)
{
    if (gameManager->hasPlayed == 1)
        freeTexture(score->texture);

    TTF_CloseFont(score->font);
    score->font = NULL;

    free(score);
    score = NULL;
}
