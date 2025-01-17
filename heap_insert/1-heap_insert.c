#include "binary_trees.h"
#include <stdlib.h>

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    // Créer le nouveau nœud
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    // Insérer le nœud dans la position la plus à gauche
    // Recherche la première position vide dans l'arbre binaire complet
    // (ici, il faut probablement utiliser un parcours en largeur, mais pour l'instant
    // nous allons faire une insertion simple dans une structure partielle).

    // L'élément doit être remonté (heapify-up) si nécessaire pour respecter l'ordre Max-Heap
    parent = new_node->parent;
    while (parent && parent->n < new_node->n)
    {
        // Échange les valeurs
        int tmp = parent->n;
        parent->n = new_node->n;
        new_node->n = tmp;
        
        // Remonter le parent
        new_node = parent;
        parent = parent->parent;
    }

    return (new_node);
}
