#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"
#include "GridModel.h"
#include "Letter.h"

typedef struct _letter Letter;

typedef struct _grid
{
    Letter*** grid;
} Grid;

Grid* createGrid(void);

int isValidLetterGrid(Grid*, Letter*, Letter*);
Letter* getLetterCoord(Grid*, int, int);
void unselectAllLetters(Grid*);

void renderGrid(Grid*, SDL_Renderer*);

void freeGrid(Grid*);

#endif // GRID_H
