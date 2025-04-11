#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *prev = list; // Initialiser prev à list pour éviter qu'il soit NULL

    while (list != NULL && list->express != NULL && value > list->express->n)
    {
        prev = list;
        list = list->express;
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
    }

    if (list != NULL && list->express != NULL)
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, list->index);
    else if (list != NULL)
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, list->index);

    while (list != NULL && list->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        list = list->next;
    }

    if (list != NULL && list->n == value)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        return list;
    }

    if (list != NULL)
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
    else
        printf("Value checked at index [nil]\n");

    return NULL;
}
