#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdbool.h>

#define SIZE 3

bool there_are_unstable_cells(
int grid[SIZE][SIZE]);

void topple(int grid[SIZE][SIZE]);

void sandpiles_sum(int grid1[SIZE][SIZE],
int grid2[SIZE][SIZE]);

#endif
