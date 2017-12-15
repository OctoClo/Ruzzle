#include "Letter.h"

Letter* createLetter(char c, int x, int y, Modifier modif)
{
    Letter* letter = malloc(sizeof(Letter));
    letter->modif = modif;
    letter->x = x;
    letter->y = y;
    letter->selected = 0;

    switch (c)
    {
    case 'a': case 'e': case 'i': case 'l': case 'n': case 'o': case 'r': case 's': case 't': case 'u':
        letter->weight = 1;
        break;
    case 'd': case 'g': case 'm':
        letter->weight = 2;
        break;
    case 'b': case 'c': case 'p':
        letter->weight = 3;
        break;
    case 'f': case 'h': case 'v':
        letter->weight = 4;
        break;
    case 'j': case 'q':
        letter->weight = 8;
        break;
    case 'k': case 'w': case 'x': case 'y': case 'z':
        letter->weight = 10;
        break;
    default: // TODO: handle exception
        letter->weight = 0;
        letter->character = ' ';
        break;
    }
    letter->character = c;

    letter->tile = malloc(sizeof letter->tile);
    char tilePath[50] = "./resources/assets/letters/letter_";
    char extension[5] = ".png";
    int tileLength = strlen("./resources/assets/letters/letter_");
    tilePath[tileLength] = letter->character;
    tilePath[tileLength + 1] = '\0';
    strcat(tilePath, extension);

    if (createImageTexture(letter->tile, tilePath, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during letter's texture creation", "IMG");

    letter->selectedTile = malloc(sizeof letter->selectedTile);
    char selectedTilePath[50] = "./resources/assets/letters/s_letter_";
    int selectedTileLength = strlen("./resources/assets/letters/s_letter_");
    selectedTilePath[selectedTileLength] = letter->character;
    selectedTilePath[selectedTileLength + 1] = '\0';
    strcat(selectedTilePath, extension);

    if (createImageTexture(letter->selectedTile, selectedTilePath, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during letter's selected texture creation", "IMG");

    if (letter->modif != NONE)
    {
        letter->bonus = malloc(sizeof letter->bonus);

        char bonusPath[50] = "./resources/assets/bonuses/bonus_";
        switch (letter->modif)
        {
        case DOUBLE_LETTER:
            strcat(bonusPath, "dl\0");
            break;
        case TRIPLE_LETTER:
            strcat(bonusPath, "tl\0");
            break;
        case DOUBLE_WORD:
            strcat(bonusPath, "dw\0");
            break;
        case TRIPLE_WORD:
            strcat(bonusPath, "tw\0");
            break;
        }
        strcat(bonusPath, extension);

        if (createImageTexture(letter->bonus, bonusPath, gameManager->renderer) == SDL_FALSE)
            fatalError("Error during bonus' texture creation", "IMG");
    }

    return letter;
}


int scoreLetter(Letter* l)
{
    int score;

    switch(l->modif)
    {
    case DOUBLE_LETTER:
        score = l->weight*2;
        break;
    case TRIPLE_LETTER:
        score = l->weight*3;
        break;
    case DOUBLE_WORD:
        score = l->weight;
        break;
    case TRIPLE_WORD:
        score = l->weight;
        break;
    case NONE:
        score = l->weight;
        break;
    default:
        score = l->weight;
        break;
    }

    return score;
}

void setSelectedLetter(Letter* letter, int selected)
{
    letter->selected = selected;
}

void renderLetter(Letter* letter, SDL_Renderer* renderer)
{
    if (letter->selected == 0)
    {
        renderTexture(letter->tile, letter->x, letter->y, renderer);
        if (letter->modif != NONE)
            renderTexture(letter->bonus, letter->x - 4, letter->y - 4, renderer);
    }
    else
        renderTexture(letter->selectedTile, letter->x, letter->y, renderer);
}

void freeLetter(Letter* letter)
{
    freeTexture(letter->tile);
    if (letter->modif != NONE)
        freeTexture(letter->bonus);
}
