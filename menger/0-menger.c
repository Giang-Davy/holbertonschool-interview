#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * Menger - Fonction récursive pour dee à un niveau donné.
 *
 * @: La position en x de la cellule dans la grille.
 * @: La position en y de la cellule dans la grille.
 * @level: Le niveau du Menger Sponge à dessiner.
 *
 * La fonction affiche un caractèreelon la position
 * dans la grille et le niveau. La cellule  est laissée vide.
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
