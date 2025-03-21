#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * Dessine une éponge de Menger de niveau donné.
 * @param level : Niveau de l'éponge (si < 0, ne fait rien).
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
