#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * Implements the top-down merge sort algorithm.
 *
 * @array: Pointer to the array to sort.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_rec(array, buffer, 0, size);
	free(buffer);
}

/**
 * merge_sort_rec - Recursively divides and sorts portions of the array.
 *
 * @array: The array to sort.
 * @buffer: Auxiliary buffer array used during merge.
 * @left: Starting index of the subarray.
 * @right: Ending index (exclusive) of the subarray.
 *
 * Return: Nothing.
 */
void merge_sort_rec(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_sort_rec(array, buffer, left, mid);
	merge_sort_rec(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge - Merges two sorted subarrays into one sorted array.
 * Prints the merging process step-by-step.
 *
 * @array: The original array being sorted.
 * @buffer: Auxiliary buffer used for merging.
 * @left: Starting index of the left subarray.
 * @mid: Ending index of the left and starting of right subarray.
 * @right: Ending index (exclusive) of the right subarray.
 *
 * Return: Nothing.
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
		buffer[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < mid)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
