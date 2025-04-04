#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> /* Inclusion pour SIZE_MAX */
#include "binary_trees.h"

/**
 * create_node - Creates a new binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
binary_tree_t *create_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
	{
		fprintf(stderr, "Error: Could not allocate memory for node\n");
		return (NULL);
	}
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * helper - Recursively builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the current subarray.
 * @end: Ending index of the current subarray.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the root node of the subtree, or NULL on failure.
 */
binary_tree_t *helper(
		int *array, size_t start, size_t end, binary_tree_t *parent)
{
	if (start > end)
		return (NULL);
	if (end >= SIZE_MAX || start >= SIZE_MAX || end < start)
	{
		return (NULL);
	}

	size_t mid = start + (end - start) / 2; /* Calcul sécurisé de mid */
	binary_tree_t *node = create_node(parent, array[mid]);

	if (!node)
		return (NULL);
	node->left = helper(array, start, mid - 1, node);
	node->right = helper(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer root node of the created AVL tree, or NULL on failure.
 */
binary_tree_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
	{
		return (NULL);
	}

	return (helper(array, 0, size - 1, NULL));
}
