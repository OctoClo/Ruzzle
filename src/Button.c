#include "Button.h"

Button* createButton(char* tilePath, int x, int y)
{
    Button* button = malloc(sizeof(Button));

    button->x = x;
    button->y = y;

    button->tile = malloc(sizeof(Texture));
    if (createImageTexture(button->tile, tilePath, gameManager->renderer) == SDL_FALSE)
        fatalError("Error during button's image texture creation", "IMG");

    return button;
}

int isClickedButton(Button* button, int x, int y)
{
    return (x >= button->x && x <= (button->x + button->tile->width)
        &&  y >= button->y && y <= (button->y + button->tile->height)) ? 1 : 0;
}

void renderButton(Button* button, SDL_Renderer* renderer)
{
    renderTexture(button->tile, button->x, button->y, renderer);
}

void freeButton(Button* button)
{
    freeTexture(button->tile);

    free(button);
    button = NULL;
}
