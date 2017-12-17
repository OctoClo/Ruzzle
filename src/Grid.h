#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"
#include "GridModel.h"
#include "Letter.h"

typedef struct _grid
{
    Letter*** grid;
} Grid;

Grid* createGrid(void);

Letter* getLetterCoord(Grid*, int, int);
void unselectAllLetters(Grid*);

void renderGrid(Grid*, SDL_Renderer*);

void freeGrid(Grid*);

#endif // GRID_H
