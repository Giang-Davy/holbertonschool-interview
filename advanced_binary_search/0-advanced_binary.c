#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the array being searched
 * @array: The array to be printed
 * @left: Left index
 * @right: Right index
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for a value in an array
 * @array: The array to search in
 * @left: Left index
 * @right: Right index
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);
	print_array(array, left, right);
	mid = (left + right) / 2;

	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return ((int)mid);
	else if (array[mid] >= value)
		return (recursive_search(array, left, mid, value));
	return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: The array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (recursive_search(array, 0, size - 1, value));
}
