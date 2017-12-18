#include "Grid.h"

Grid* createGrid(void)
{
    Grid* grid = malloc(sizeof(Grid));

    GridModel gridModel = createGridModel();

    grid->grid = malloc(GRID_SIZE * sizeof(Letter**));

    int row, column;
    for (row = 0; row < GRID_SIZE; row++)
    {
        grid->grid[row] = malloc(GRID_SIZE * sizeof(Letter*));
        for (column = 0; column < GRID_SIZE; column++)
        {
            grid->grid[row][column] = malloc(sizeof(Letter));
            grid->grid[row][column] = createLetter( gridModel.grid[row][column].c,
                                                    ((row * GRID_CELL_SIZE) + BEGIN_GRID_X + PIXELS_TO_CENTER_LETTER),
                                                    ((column * GRID_CELL_SIZE) + BEGIN_GRID_Y + PIXELS_TO_CENTER_LETTER), column, row,
                                                    gridModel.grid[column][row].m);
        }
    }

    return grid;
}

Letter* getLetterCoord(Grid* grid, int x, int y)
{
    int newX = x - BEGIN_GRID_X, newY = y - BEGIN_GRID_Y;

    if (newX < 0 || newY < 0 || newX > (GRID_SIZE * GRID_CELL_SIZE) || newY > (GRID_SIZE * GRID_CELL_SIZE))
        return NULL;

    if (abs((newX % GRID_CELL_SIZE) - (GRID_CELL_SIZE / 2)) <= (LETTER_ASSET_PIXELS / 2) &&
        abs((newY % GRID_CELL_SIZE) - (GRID_CELL_SIZE / 2)) <= (LETTER_ASSET_PIXELS / 2))
    {
        return grid->grid[newX / GRID_CELL_SIZE][newY / GRID_CELL_SIZE];
    }
    else
        return NULL;
}

void unselectAllLetters(Grid* grid)
{
    int row, column;
    for (row = 0; row < GRID_SIZE; row++)
    {
        for (column = 0; column < GRID_SIZE; column++)
            setSelectedLetter(grid->grid[row][column], 0);
    }
}

void generateGrid(int size){
    FILE* gridFile = NULL;

    gridFile = fopen("src/file/grid.txt", "w");
    srand(time(NULL));
    if(gridFile != NULL){
        int row, column;
        fprintf(gridFile, "%d\n", size);
        for(row=0; row<size; row++){
            for(column=0; column<size; column++){
                fprintf(gridFile, "[%c,%d]", randLetter(), randModifier());
            }
            fprintf(gridFile, "|\n");
        }

        fclose(gridFile);
    }else{
        SDL_Log("Error file");
    }

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
            freeLetter(grid->grid[row][column]);
    }
    free(grid->grid);
    free(grid);
    grid = NULL;
}
