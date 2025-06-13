#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);

static void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];
}

static void top_down_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	size_t mid = size / 2;

	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));

	if (!left || !right)
		return;

	for (size_t i = 0; i < mid; i++)
		left[i] = array[i];

	for (size_t i = mid; i < size; i++)
		right[i - mid] = array[i];

	top_down_sort(left, mid);
	top_down_sort(right, size - mid);
	merge(array, left, mid, right, size - mid);

	free(left);
	free(right);

	print_array(array, size);
}

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	top_down_sort(array, size);
}
