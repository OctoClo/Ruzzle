#ifndef INTERFACE_BEGIN_H
#define INTERFACE_BEGIN_H

#include <SDL2/SDL.h>

#include "Texture.h"
#include "Button.h"

typedef struct _interfaceBegin
{
    Texture* imgLogo;
    int xImgLogo, yImgLogo;
    Texture* textLogo;
    int xTextLogo, yTextLogo;

    Button* buttonPlay;
    Button* buttonQuit;
} InterfaceBegin;

InterfaceBegin* createInterfaceBegin(void);

void handleClickInterfaceBegin(InterfaceBegin*, SDL_Event*);
void renderInterfaceBegin(InterfaceBegin*, SDL_Renderer*);

void freeInterfaceBegin(InterfaceBegin*);

#endif // INTERFACE_BEGIN_H
