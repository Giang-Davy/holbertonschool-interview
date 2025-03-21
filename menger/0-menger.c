#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * drawMenger - Fonction récursive pour dessiner un Menger Sponge à un niveau donné.
 *
 * @x: La position en x de la cellule dans la grille.
 * @y: La position en y de la cellule dans la grille.
 * @level: Le niveau du Menger Sponge à dessiner.
 *
 * La fonction affiche un caractère '#' ou un espace (' ') selon la position
 * dans la grille et le niveau. La cellule centrale des sous-blocs 3x3 est laissée vide.
 */

void menger(int level)
{
	if (level < 0)
		return;
	int size = pow(3, level);

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			int r = row, c = col;

			char isSpace = '#';
			while (r > 0 || c > 0)
			{
				if (r % 3 == 1 && c % 3 == 1)
				{
					isSpace = ' ';
					break;
				}
				r /= 3;
				c /= 3;
			}
			putchar(isSpace);
		}
		putchar('\n');
	}
}
