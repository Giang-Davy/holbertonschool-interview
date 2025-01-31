#include <stdbool.h>
#include <stdio.h>

#define SIZE 3

/**
 * there_are_unstable_cells - Check if there are any unstable cells in the grid.
 * @grid: The grid to check.
 *
 * Return: true if there are unstable cells, false otherwise.
 */
bool there_are_unstable_cells(int grid[SIZE][SIZE])
{
    int i;
    int j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (grid[i][j] > 3)
            {
                return (true);
            }
        }
    }
    return (false);
}

/**
 * print_grid - Prints the 3x3 grid.
 * @grid: The grid to print.
 */
void print_grid(int grid[SIZE][SIZE])
{
    int i;
    int j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (j)
            {
                printf(" ");
            }
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * topple - Performs the toppling of unstable cells in the grid.
 * @grid: The grid to perform the toppling on.
 */
void topple(int grid[SIZE][SIZE])
{
    int temp_grid[SIZE][SIZE] = {0};
    int i;
    int j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (grid[i][j] > 3)
            {
                temp_grid[i][j] -= 4;

                if (i > 0)
                    temp_grid[i - 1][j] += 1;
                if (i < SIZE - 1)
                    temp_grid[i + 1][j] += 1;
                if (j > 0)
                    temp_grid[i][j - 1] += 1;
                if (j < SIZE - 1)
                    temp_grid[i][j + 1] += 1;
            }
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            grid[i][j] += temp_grid[i][j];
        }
    }
}

/**
 * sandpiles_sum - Sums two sandpiles grids and performs toppling until stable.
 * @grid1: The first grid.
 * @grid2: The second grid.
 */
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE])
{
    int i;
    int j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    if (there_are_unstable_cells(grid1))
    {
        printf("=\n");
        print_grid(grid1);
    }

    while (there_are_unstable_cells(grid1))
    {
        topple(grid1);

        if (there_are_unstable_cells(grid1))
        {
            printf("=\n");
            print_grid(grid1);
        }
    }
}
