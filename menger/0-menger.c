#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 *         If level is less than 0, the function does nothing.
 * Description:
 * The function generates a fractal-like pattern (Menger Sponge)
 * where each level is a 3x3 grid of the previous level, with
 * the center removed at each iteration.
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
