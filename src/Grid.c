#include "Grid.h"

Grid* createGrid(GameManager* gameManager)
{
    Grid* grid = malloc(sizeof(Grid));

    GridModel gridModel = createGridModel();

    grid->grid = (Letter***) malloc(GRID_SIZE * sizeof(Letter**));

    int row, column;
    for (row = 0; row < GRID_SIZE; row++)
    {
        grid->grid[row] = (Letter**) malloc(GRID_SIZE * sizeof(Letter*));
        for (column = 0; column < GRID_SIZE; column++)
        {
            grid->grid[row][column] = (Letter*) malloc(sizeof(Letter));
            grid->grid[row][column] = createLetter( gameManager,
                                                    gridModel.grid[column][row].c,
                                                    ((row * GRID_CELL_SIZE) + BEGIN_GRID_X + PIXELS_TO_CENTER_LETTER),
                                                    ((column * GRID_CELL_SIZE) + BEGIN_GRID_Y + PIXELS_TO_CENTER_LETTER),
                                                    gridModel.grid[column][row].m);
        }
    }

    return grid;
}

void renderGrid(Grid* grid, SDL_Renderer* renderer)
{
    int row, column;
    for (row = 0; row < GRID_SIZE; row++)
    {
        for (column = 0; column < GRID_SIZE; column++)
            renderLetter(grid->grid[row][column], renderer);
    }
}

void freeGrid(Grid* grid)
{
    int row, column;
    for (row = 0; row < GRID_SIZE; row++)
    {
        for (column = 0; column < GRID_SIZE; column++)
        {
            freeLetter(grid->grid[row][column]);
            free(grid->grid[row][column]);
        }
    }
    free(grid->grid);
}
