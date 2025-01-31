#include <stdbool.h>

#define SIZE 3

// Fonction pour vérifier s'il y a des cellules instables
bool there_are_unstable_cells(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] > 3) {
                return true;  // Il y a une cellule instable
            }
        }
    }
    return false;  // Toutes les cellules sont stables
}

// Fonction pour effectuer un renversement des grains de sable
void topple(int grid[SIZE][SIZE]) {
    // Applique le renversement aux cellules instables
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] > 3) {
                grid[i][j] -= 4;  // La cellule instable perd 4 grains

                // Renverser les grains vers les voisins
                if (i > 0) grid[i-1][j] += 1;  // Haut
                if (i < SIZE - 1) grid[i+1][j] += 1;  // Bas
                if (j > 0) grid[i][j-1] += 1;  // Gauche
                if (j < SIZE - 1) grid[i][j+1] += 1;  // Droite
            }
        }
    }
}

// Fonction pour additionner les grilles et effectuer les renversements
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]) {
    // Additionner grid1 et grid2
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Effectuer les renversements jusqu'à ce que la grille soit stable
    while (there_are_unstable_cells(grid1)) {
        // Effectuer un renversement
        topple(grid1);
    }
}
