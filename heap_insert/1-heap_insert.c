#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - Ensures the max heap property by swapping upwards
 *
 * @node: Pointer to the node to heapify
 *
 * Return: Pointer to the new position of the node after heapify
 */
static heap_t *heapify_up(heap_t *node)
{
	heap_t *current = node;
	int temp;

	while (current->parent && current->n > current->parent->n)
	{
		temp = current->n;
		current->n = current->parent->n;
		current->parent->n = temp;
		current = current->parent;
	}

	return (current);
}

/**
 * find_insert_position - Finds the first empty position in level order
 *
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the parent node where a new node can be inserted
 */
static heap_t *find_insert_position(heap_t *root)
{
	heap_t **queue;
	heap_t *current;
	size_t head = 0, tail = 0;

	queue = malloc(1024 * sizeof(heap_t *));
	if (!queue)
		return (NULL);

	queue[tail++] = root;
	while (head < tail)
	{
		current = queue[head++];
		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}
		queue[tail++] = current->left;
		queue[tail++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insert_position(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
