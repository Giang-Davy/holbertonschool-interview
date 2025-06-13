#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_subarray - Prints a portion of an array from index `start` to `end`.
 *
 * @array: The array to print from.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 *
 * Return: Nothing.
 */
void print_subarray(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge - Merges two sorted subarrays into one sorted array.
 * Also prints the merging steps for visualization.
 *
 * @array: The main array containing both subarrays.
 * @buffer: Auxiliary array used to store merged results.
 * @left: Starting index of the left subarray.
 * @mid: Ending index of the left subarray.
 * @right: Ending index of the right subarray.
 *
 * Return: Nothing.
 */
void merge(int *array, int *buffer, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;

	printf("Merging...\n");

	printf("[left]: ");
	print_subarray(array, left, mid);

	printf("[right]: ");
	print_subarray(array, mid + 1, right);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i <= mid)
		buffer[k++] = array[i++];

	while (j <= right)
		buffer[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_subarray(array, left, right);
}

/**
 * merge_sort_rec - Recursively sorts a subarray using merge sort algorithm.
 *
 * @array: The array to be sorted.
 * @buffer: Auxiliary array used during merging.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 *
 * Return: Nothing.
 */
void merge_sort_rec(int *array, int *buffer, int left, int right)
{
	if (left >= right)
		return;

	int size = right - left + 1;
	int mid = left + (size / 2) - 1;

	merge_sort_rec(array, buffer, left, mid);
	merge_sort_rec(array, buffer, mid + 1, right);

	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 *
 * @array: Pointer to the array to sort.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int *buffer = malloc(size * sizeof(int));

	if (!buffer)
		return;

	merge_sort_rec(array, buffer, 0, (int)size - 1);

	free(buffer);
}
