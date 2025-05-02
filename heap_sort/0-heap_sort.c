#include "sort.h"

/**
 * sift_down - Maintains the max heap property by sifting a node down
 * @array: Pointer to the array
 * @size: Total size of the array (for print)
 * @start: Index of the root node of the subtree
 * @end: Index of the last element of the heap
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, child, swap;
	int temp;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if ((child + 1) <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 *
 * Description: Uses sift-down to maintain the heap
 * Prints the array after each swap
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;
	int temp;

	if (!array || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
