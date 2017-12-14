#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>

#include "GridModel.h"
#include "Letter.h"
#include "GameManager.h"
#include "Utils.h"

typedef struct
{
    Letter*** grid;
} Grid;

Grid* createGrid(GameManager*);
void renderGrid(Grid*, SDL_Renderer*);

void freeGrid(Grid*);

#endif // GRID_H
