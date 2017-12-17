#ifndef GRID_MODEL_H
#define GRID_MODEL_H

#include "Utils.h"
#include "Enums.h"

typedef struct _pairGrid
{
    char c;
    Modifier m;
} PairGrid;

typedef struct _gridModel
{
    PairGrid grid[GRID_SIZE][GRID_SIZE];
} GridModel;

GridModel createGridModel();

#endif // GRID_MODEL_H
