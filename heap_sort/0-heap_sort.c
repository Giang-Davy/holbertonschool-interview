#include "sort.h"

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
