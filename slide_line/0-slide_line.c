#include <stdlib.h>
#include "slide_line.h"

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    if (direction == SLIDE_LEFT)
    {
        size_t i, j = 0;

        /* Déplacement des valeurs non-nulles vers la gauche */
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
                line[j++] = line[i];
        }

        /* Remplir le reste de la ligne avec des zéros */
        while (j < size)
            line[j++] = 0;

        /* Fusion des valeurs égales adjacentes */
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == line[i + 1] && line[i] != 0)
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        /* Déplacer les valeurs non-nulles vers la gauche après la fusion */
        j = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
                line[j++] = line[i];
        }
        while (j < size)
            line[j++] = 0;
    }
    else if (direction == SLIDE_RIGHT)
    {
        size_t i, j = size - 1;

        /* Déplacement des valeurs non-nulles vers la droite */
        for (i = size; i > 0; i--)
        {
            if (line[i - 1] != 0)
                line[j--] = line[i - 1];
        }

        /* Remplir le reste de la ligne avec des zéros */
        while (j < size)
            line[j--] = 0;

        /* Fusion des valeurs égales adjacentes */
        for (i = size; i > 1; i--)
        {
            if (line[i - 1] == line[i - 2] && line[i - 1] != 0)
            {
                line[i - 1] *= 2;
                line[i - 2] = 0;
            }
        }

        /* Déplacer les valeurs non-nulles vers la droite après la fusion */
        j = size - 1;
        for (i = size; i > 0; i--)
        {
            if (line[i - 1] != 0)
                line[j--] = line[i - 1];
        }
        while (j < size)
            line[j--] = 0;
    }

    return 1;
}
