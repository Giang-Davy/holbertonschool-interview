#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int *buffer, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;

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

	printf("Merging [%d..%d]: ", left, right);
	for (i = left; i <= right; i++)
		printf("%d%s", array[i], i == right ? "\n" : ", ");
}

void merge_sort_rec(int *array, int *buffer, int left, int right)
{
	if (left >= right)
		return;

	int size = right - left + 1;
	int mid = left + (size / 2) - 1; // gauche <= droite

	merge_sort_rec(array, buffer, left, mid);
	merge_sort_rec(array, buffer, mid + 1, right);

	merge(array, buffer, left, mid, right);
}

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
