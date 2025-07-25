#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * height - Calcule la hauteur d'un arbre binaire
 * @tree: pointeur vers la racine
 * Return: hauteur
 */
int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = height(tree->left);
	right = height(tree->right);
	return ((left > right ? left : right) + 1);
}

/**
 * is_avl - Fonction récursive pour valider AVL et BST
 * @tree: nœud courant
 * @min: borne inférieure permise
 * @max: borne supérieure permise
 * Return: 1 si valide, 0 sinon
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int balance;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	balance = height(tree->left) - height(tree->right);
	if (balance < -1 || balance > 1)
		return (0);

	return (is_avl(tree->left, min, tree->n) &&
	        is_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Vérifie si un arbre est un AVL valide
 * @tree: pointeur vers la racine de l'arbre
 * Return: 1 si oui, 0 sinon
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
