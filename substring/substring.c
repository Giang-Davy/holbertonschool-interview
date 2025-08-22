#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substring.h"

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
	int word_len, total_len, s_len, i, j;
	int *result, result_size = 0;

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
		int matched = 1;
		int *used = calloc(nb_words, sizeof(int));
		if (!used)
		{
			free(result);
			return (NULL);
		}

		for (j = 0; j < nb_words; j++)
		{
			int k;
			int word_matched = 0;
			for (k = 0; k < nb_words; k++)
			{
				if (!used[k] &&
					strncmp(s + i + j * word_len, words[k], word_len) == 0)
				{
					used[k] = 1;
					word_matched = 1;
					break;
				}
			}
			if (!word_matched)
			{
				matched = 0;
				break;
			}
		}

		free(used);
		if (matched)
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
