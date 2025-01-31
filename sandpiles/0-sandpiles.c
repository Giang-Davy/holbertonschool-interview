#include <stdbool.h>
#include <stdio.h>

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

// Fonction pour afficher la grille
void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j) {
                printf(" ");
            }
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour effectuer un renversement des grains de sable
void topple(int grid[SIZE][SIZE]) {
    int temp_grid[SIZE][SIZE] = {0};  // Créer une grille temporaire pour stocker les changements

    // Applique le renversement aux cellules instables
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] > 3) {
                temp_grid[i][j] -= 4;  // La cellule instable perd 4 grains

                // Renverser les grains vers les voisins dans la grille temporaire
                if (i > 0) temp_grid[i-1][j] += 1;  // Haut
                if (i < SIZE - 1) temp_grid[i+1][j] += 1;  // Bas
                if (j > 0) temp_grid[i][j-1] += 1;  // Gauche
                if (j < SIZE - 1) temp_grid[i][j+1] += 1;  // Droite
            }
        }
    }

    // Mettre à jour la grille avec les valeurs de la grille temporaire
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] += temp_grid[i][j];
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

    // Afficher la grille avant les renversements si elle est instable
    if (there_are_unstable_cells(grid1)) {
        printf("=\n");
        print_grid(grid1);  // Afficher la grille avant le premier renversement
    }

    // Effectuer les renversements jusqu'à ce que la grille soit stable
    while (there_are_unstable_cells(grid1)) {
        // Effectuer un renversement
        topple(grid1);

        // Afficher la grille après chaque renversement, sauf si elle est stable
        if (there_are_unstable_cells(grid1)) {
            printf("=\n");
            print_grid(grid1);
        }
    }
}
