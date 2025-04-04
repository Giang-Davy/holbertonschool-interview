#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef binary_tree_t avl_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *sorted_array_to_avl(int *array, size_t size);

#endif /* _BINARY_TREES_H_ */
