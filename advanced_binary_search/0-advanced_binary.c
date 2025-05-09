#include <stdio.h>
#include "search_algos.h"

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

int recursive_search(int *array, size_t left, size_t right, int value)
{
        size_t mid;

        if (left > right)
                return (-1);

        print_array(array, left, right);
        mid = (left + right) / 2; // Simplification du calcul de mid

        if (array[mid] == value && (mid == left || array[mid - 1] != value))
                return ((int)mid);
        else if (array[mid] >= value) // Combine la condition pour inclure mid
                return (recursive_search(array, left, mid, value));
        return (recursive_search(array, mid + 1, right, value));
}

int advanced_binary(int *array, size_t size, int value)
{
        if (!array || size == 0)
                return (-1);
        return (recursive_search(array, 0, size - 1, value));
}
