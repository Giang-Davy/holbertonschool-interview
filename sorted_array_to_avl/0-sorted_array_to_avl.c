#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *create_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));
    if (!node)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

binary_tree_t *helper(int *array, size_t start, size_t end, binary_tree_t *parent)
{
    if (start > end)
        return NULL;

    size_t mid = (start + end) / 2;
    binary_tree_t *node = create_node(parent, array[mid]);
    if (!node)
        return NULL;

    node->left = helper(array, start, mid - 1, node);
    node->right = helper(array, mid + 1, end, node);

    return node;
}

binary_tree_t *sorted_array_to_avl(int *array, size_t size)
{
    return helper(array, 0, size - 1, NULL);
}
