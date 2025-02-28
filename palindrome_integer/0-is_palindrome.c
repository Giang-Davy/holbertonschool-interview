#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_palindrome(unsigned long n)
{
    if (n < 10)  // Si n est un seul chiffre, c'est un palindrome
    {
        return 1;
    }

    unsigned long comparaison = n;  // Conserver l'original pour la comparaison
    unsigned long rev = 0;

    // Inversion du nombre
    while (n != 0) 
    {
        rev = rev * 10 + n % 10;  // Ajoute le dernier chiffre de n à rev
        n = n / 10;  // Enlève le dernier chiffre de n
    }

    // Comparaison du nombre inversé avec l'original
    if (rev == comparaison)
    {
        return 1;  // C'est un palindrome
    }
    else
    {
        return 0;  // Ce n'est pas un palindrome
    }
}
