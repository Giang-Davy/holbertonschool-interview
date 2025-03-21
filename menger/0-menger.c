#include <stdio.h>
#include <math.h>
#include "menger.h"

void drawMenger(int x, int y, int level, int size) {
    // Base case: If level is 0, print '#'
    if (level == 0) {
        printf("#");
        return;
    }

    // Calculate the size of the current level's sponge
    int blockSize = pow(3, level);

    // If the position is in the center of a block, skip it
    if ((x / blockSize) % 3 == 1 && (y / blockSize) % 3 == 1) {
        printf(" ");
    } else {
        // Recurse into smaller blocks
        drawMenger(x, y, level - 1, size);
    }
}

void menger(int level) {
    if (level < 0) return;

    // Calculate the size of the sponge at this level
    int size = pow(3, level);

    // Draw the sponge row by row
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            drawMenger(i, j, level, size);
        }
        printf("\n");
    }
}
