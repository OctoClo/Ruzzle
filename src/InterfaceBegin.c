#include "InterfaceBegin.h"

InterfaceBegin* createInterfaceBegin(void)
{
    InterfaceBegin* interfaceBegin = malloc(sizeof(InterfaceBegin));

    interfaceBegin->imgLogo = malloc(sizeof(Texture));
    if (createImageTexture(interfaceBegin->imgLogo, "./resources/assets/logo/logoImg.png", gameManager->renderer) == SDL_FALSE)
        fatalError("Error during image logo's texture creation", "IMG");
    interfaceBegin->xImgLogo = 200;
    interfaceBegin->yImgLogo = 30;

    interfaceBegin->textLogo = malloc(sizeof(Texture));
    if (createImageTexture(interfaceBegin->textLogo, "./resources/assets/logo/logoText.png", gameManager->renderer) == SDL_FALSE)
        fatalError("Error during text logo's texture creation", "IMG");
    interfaceBegin->xTextLogo = 0;
    interfaceBegin->yTextLogo = 162;

    interfaceBegin->buttonPlay = createButton("./resources/assets/buttons/begin/button_play.png", 100, 300);
    interfaceBegin->buttonQuit = createButton("./resources/assets/buttons/begin/button_quit.png", 100, 500);

    return interfaceBegin;
}

void handleClickInterfaceBegin(InterfaceBegin* interfaceBegin, SDL_Event* e)
{
    if (e->button.button == SDL_BUTTON_LEFT)
    {
        if (isClickedButton(interfaceBegin->buttonPlay, e->button.x, e->button.y) == 1)
            setStep(GAME);
        else if (isClickedButton(interfaceBegin->buttonQuit, e->button.x, e->button.y) == 1)
            setStep(QUIT);
    }
}

void renderInterfaceBegin(InterfaceBegin* interfaceBegin, SDL_Renderer* renderer)
{
    renderTexture(interfaceBegin->imgLogo, interfaceBegin->xImgLogo, interfaceBegin->yImgLogo, renderer);
    renderTexture(interfaceBegin->textLogo, interfaceBegin->xTextLogo, interfaceBegin->yTextLogo, renderer);
    renderButton(interfaceBegin->buttonPlay, renderer);
    renderButton(interfaceBegin->buttonQuit, renderer);
}

void freeInterfaceBegin(InterfaceBegin* interfaceBegin)
{
    freeButton(interfaceBegin->buttonQuit);
    freeButton(interfaceBegin->buttonPlay);

    freeTexture(interfaceBegin->textLogo);
    freeTexture(interfaceBegin->imgLogo);

    free(interfaceBegin);
    interfaceBegin = NULL;
}

