#include "holberton.h"
#include <stdio.h>
/**
 * wildcmp - Compare deux chaînes de caractères, où la deuxième
 *           peut contenir le caractère spécial '*' qui remplace
 *           n'importe quelle chaîne (y compris vide).
 * @s1: Première chaîne de caractères à comparer.
 * @s2: Deuxième chaîne de caractères à comparer (peut contenir '*').
 *
 * Return: 1 si les chaînes peuvent être considérées identiques, 0 sinon.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
		return (0);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
