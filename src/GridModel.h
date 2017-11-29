#ifndef GRID_MODEL_H
#define GRID_MODEL_H

#include "Letter.h"

typedef struct
{
    char c;
    Modifier m;
} PairGrid;

typedef struct
{
    PairGrid grid[4][4];
} GridModel;

GridModel createGridModel();

#endif // GRID_MODEL_H
