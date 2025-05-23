#include <stdlib.h>
#include "binary_trees.h"

/* Structure pour la queue utilisée en parcours largeur */
typedef struct queue_s
{
	heap_t *node;
	struct queue_s *next;
} queue_t;


static void enqueue(queue_t **head, queue_t **tail, heap_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	if (!new_node)
		return;
	new_node->node = node;
	new_node->next = NULL;
	if (*tail)
		(*tail)->next = new_node;
	else
		*head = new_node;
	*tail = new_node;
}

static heap_t *dequeue(queue_t **head, queue_t **tail)
{
	if (!*head)
		return NULL;
	queue_t *tmp = *head;
	heap_t *node = tmp->node;
	*head = tmp->next;
	if (!*head)
		*tail = NULL;
	free(tmp);
	return node;
}

/* Trouve le dernier noeud dans le tas (parcours en largeur) */
static heap_t *find_last_node(heap_t *root)
{
	queue_t *head = NULL, *tail = NULL;
	heap_t *current = NULL;

	enqueue(&head, &tail, root);
	while (head)
	{
		current = dequeue(&head, &tail);
		if (current->left)
			enqueue(&head, &tail, current->left);
		if (current->right)
			enqueue(&head, &tail, current->right);
	}
	return current;
}

/* Supprime le dernier noeud (détache du parent) */
static void remove_last_node(heap_t *last_node)
{
	if (!last_node->parent)
		return;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	free(last_node);
}

/* Restaure la propriété Max Heap en descendant */
static void heapify_down(heap_t *node)
{
	if (!node)
		return;

	heap_t *largest = node;
	heap_t *left = node->left;
	heap_t *right = node->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		int tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;
		heapify_down(largest);
	}
}

int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node;

	if (root == NULL || *root == NULL)
		return 0;

	extracted_value = (*root)->n;

	last_node = find_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return extracted_value;
	}

	(*root)->n = last_node->n;
	remove_last_node(last_node);
	heapify_down(*root);
	return extracted_value;
}
