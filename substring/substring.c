#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * is_valid_substring - Checks if a substring contains all words
 * @s: Starting point in the string
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid_substring(char const *s, char const **words,
			      int nb_words, int word_len)
{
	int i, j;
	int *used;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		int matched = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
			    strncmp(s + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				matched = 1;
				break;
			}
		}

		if (!matched)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * find_substring - Finds all starting indices of concatenated substrings
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of words
 * @n: Pointer to store number of results
 *
 * Return: Allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len, i;
	int *result;
	int result_size = 0;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	word_len = strlen(words[0]);

	total_len = word_len * nb_words;

	s_len = strlen(s);

	result = malloc(sizeof(int) * s_len);
	if (!result)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (is_valid_substring(s + i, words, nb_words, word_len))
			result[result_size++] = i;
	}

	if (result_size == 0)
	{
		free(result);
		*n = 0;
		return (NULL);
	}

	*n = result_size;
	return (result);
}
