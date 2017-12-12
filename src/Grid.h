#ifndef GRID_H
#define GRID_H

#include "GridModel.h"
#include "Letter.h"
#include "GameManager.h"

typedef struct
{
    Letter*** grid;
} Grid;

Grid* createGrid(GameManager*);
void renderGrid(Grid*, SDL_Renderer*);
void freeGrid(Grid*);

#endif // GRID_H