#include "Texture.h"

SDL_bool createImageTexture(Texture* texture, char* imagePath, SDL_Renderer* renderer)
{
    SDL_bool success = SDL_TRUE;

	SDL_Surface* imageSurface = IMG_Load(imagePath);

	if (imageSurface == NULL)
		success = SDL_FALSE;
    else
    {
        SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface->format, 0, 0xFF, 0xFF));

        texture->texture = SDL_CreateTextureFromSurface(renderer, imageSurface);

        if (texture->texture == NULL)
            success = SDL_FALSE;
        else
        {
            texture->width = imageSurface->w;
            texture->height = imageSurface->h;
        }

        SDL_FreeSurface(imageSurface);
    }

	return success;
}

SDL_bool createTextTexture(Texture* texture, char* textureText, SDL_Color* textColor, TTF_Font* font, SDL_Renderer* renderer)
{
    SDL_bool success = SDL_TRUE;

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText, *textColor);

	if (textSurface == NULL)
        success = SDL_FALSE;
    else
    {
        texture->texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (texture->texture == NULL)
            success = SDL_FALSE;
        else
        {
            texture->width = textSurface->w;
            texture->height = textSurface->h;
        }

        SDL_FreeSurface(textSurface);
    }

	return success;
}

void renderTexture(Texture* texture, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect* renderRect = malloc(sizeof(SDL_Rect));
	renderRect->x = x;
    renderRect->y = y;
	renderRect->w = texture->width;
	renderRect->h = texture->height;

	SDL_RenderCopyEx(renderer, texture->texture, NULL, renderRect, 0.0, NULL, SDL_FLIP_NONE);
}

void freeTexture(Texture* texture)
{
    if (texture->texture != NULL)
        SDL_DestroyTexture(texture->texture);

    free(texture);
    texture = NULL;
}

