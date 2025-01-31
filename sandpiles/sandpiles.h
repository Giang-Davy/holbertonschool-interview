#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdbool.h>

#define SIZE 3

// Déclaration de la fonction pour vérifier s'il y a des cellules instables
bool there_are_unstable_cells(int grid[SIZE][SIZE]);

// Déclaration de la fonction pour effectuer un renversement des grains de sable
void topple(int grid[SIZE][SIZE]);

// Déclaration de la fonction pour additionner les grilles et effectuer les renversements
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]);

#endif // SANDPILES_H
