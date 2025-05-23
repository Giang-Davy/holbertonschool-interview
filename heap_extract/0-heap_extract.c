#include <stdlib.h>
#include "binary_trees.h"

/**
	* swap - Échange les valeurs entre deux nœuds
	* @a: premier nœud
	* @b: second nœud
	*/
void swap(heap_t *a, heap_t *b)
{
	int tmp = a->n;

	a->n = b->n;
	b->n = tmp;
}

/**
	* heapify_down - Répare le tas après suppression de la racine
	* @node: nœud à ajuster
	*/
void heapify_down(heap_t *node)
{
	heap_t *max;

	if (!node)
	return;

	while (1)
	{
	max = node;
	if (node->left && node->left->n > max->n)
	max = node->left;
	if (node->right && node->right->n > max->n)
	max = node->right;

	if (max == node)
	break;

	swap(node, max);
	node = max;
	}
}

/**
	* find_last_node - Trouve le dernier nœud du tas (parcours en largeur)
	* @root: racine du tas
	* Return: pointeur vers le dernier nœud
	*/
heap_t *find_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	if (!root)
	return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
	root = queue[front++];
	if (root->left)
	queue[rear++] = root->left;
	if (root->right)
	queue[rear++] = root->right;
	}
	return (root);
}

/**
	* remove_last - Supprime le dernier nœud du tas
	* @node: nœud à supprimer
	*/
void remove_last(heap_t *node)
{
	if (!node || !node->parent)
	return;

	if (node->parent->left == node)
	node->parent->left = NULL;
	else
	node->parent->right = NULL;

	free(node);
}

/**
	* heap_extract - Extrait la racine du tas Max binaire
	* @root: double pointeur vers la racine
	* Return: valeur extraite, ou 0 si erreur
	*/
int heap_extract(heap_t **root)
{
	heap_t *last;
	int value;

	if (!root || !*root)
	return (0);

	value = (*root)->n;
	last = find_last_node(*root);

	if (last == *root)
	{
	free(*root);
	*root = NULL;
	return (value);
	}

	(*root)->n = last->n;
	remove_last(last);
	heapify_down(*root);

	return (value);
}
