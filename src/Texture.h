#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdlib.h>

typedef struct _texture
{
    SDL_Texture* texture;
    int width;
    int height;
} Texture;

SDL_bool createImageTexture(Texture*, char*, SDL_Renderer*);
SDL_bool createTextTexture(Texture*, char*, SDL_Color*, TTF_Font*, SDL_Renderer*);

void renderTexture(Texture*, int, int, SDL_Renderer*);

void freeTexture(Texture*);

#endif // TEXTURE_H

