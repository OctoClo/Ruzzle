#ifndef GRID_MODEL_H
#define GRID_MODEL_H

#include "Utils.h"
#include "Letter.h"

typedef struct
{
    char c;
    Modifier m;
} PairGrid;

typedef struct
{
    PairGrid grid[GRID_SIZE][GRID_SIZE];
} GridModel;

GridModel createGridModel();

#endif // GRID_MODEL_H
