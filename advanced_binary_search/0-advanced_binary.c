#include <stdio.h>
#include "search_algos.h"

void print_array(int *array, size_t left, size_t right)
{
	size_t i = left;

	printf("Searching in array: ");
	while (i <= right)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
		i++;
	}
	printf("\n");
}

int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);
	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return ((int)mid);
		return (recursive_search(array, left, mid, value));
	}
	else if (array[mid] > value)
		return (recursive_search(array, left, mid - 1, value));
	else
		return (recursive_search(array, mid + 1, right, value));
}

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (recursive_search(array, 0, size - 1, value));
}
