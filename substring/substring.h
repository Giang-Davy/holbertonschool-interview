#ifndef FIND_SUBSTRING_H
#define FIND_SUBSTRING_H

/**
 * find_substring - Finds all starting indices of substrings
 * that are concatenations of all words in the array
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of words
 * @n: Pointer to store number of results
 *
 * Return: Allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
