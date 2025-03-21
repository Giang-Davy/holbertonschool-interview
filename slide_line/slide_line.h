#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>  // Pour size_t

// Définition des directions
#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

// Prototype de la fonction slide_line
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
