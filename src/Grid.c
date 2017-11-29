#include "Grid.h"

Grid* createGrid(GameManager* gameManager)
{
    Grid* grid = malloc(sizeof(Grid));

    GridModel gridModel = createGridModel();

    grid->grid = (Letter***) malloc(4 * sizeof(Letter**));

    int row, column;
    for (row = 0; row < 4; row++)
    {
        grid->grid[row] = (Letter**) malloc(4 * sizeof(Letter*));
        for (column = 0; column < 4; column++)
        {
            grid->grid[row][column] = (Letter*) malloc(sizeof(Letter));
            grid->grid[row][column] = createLetterModif(gameManager,
                                                        gridModel.grid[column][row].c,
                                                        ((row * 100) + 50 + 10),
                                                        ((column * 100) + 200 + 10),
                                                        gridModel.grid[column][row].m);
        }
    }

    return grid;
}

void renderGrid(Grid* grid, SDL_Renderer* renderer)
{
    int row, column;
    for (row = 0; row < 4; row++)
    {
        for (column = 0; column < 4; column++)
            renderLetter(grid->grid[row][column], renderer);
    }
}

void freeGrid(Grid* grid)
{
    int row, column;
    for (row = 0; row < 4; row++)
    {
        for (column = 0; column < 4; column++)
        {
            freeLetter(grid->grid[row][column]);
            free(grid->grid[row][column]);
        }
    }
    free(grid->grid);
}
