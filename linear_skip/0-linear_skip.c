#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *start = NULL;
    skiplist_t *current = list;

    if (!list)
        return (NULL);

    while (current->express != NULL)
    {
        printf("Value checked at index [%lu] = [%d]\n",
               current->express->index, current->express->n);
        if (current->express->n >= value)
            break;
        current = current->express;
    }

    start = current;
    if (current->express && current->express->n >= value)
        current = current->express;
    else
    {
        while (current->next)
            current = current->next;
    }
    printf("Value found between indexes [%lu] and [%lu]\n",
           start->index, current->index);

    while (start != NULL && start->index <= current->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
        if (start->n == value)
            return (start);
        start = start->next;
    }

    return (NULL);
}
