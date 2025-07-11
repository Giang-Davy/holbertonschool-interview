#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_radix - A counting sort algorithm for Radix sort.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void counting_sort_radix(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		buff[count[(array[i - 1] / sig) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of ir using the Radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);

	for (sig = 1; max / sig > 0; sig *= 10)
	{
		counting_sort_radix(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
