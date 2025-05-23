#include <stdlib.h>
#include "binary_trees.h"

/**
 * struct queue_s - Structure pour la queue utilisée en parcours largeur
 * @node: Pointeur vers le noeud heap
 * @next: Pointeur vers le prochain élément de la queue
 */
typedef struct queue_s
{
    heap_t *node;
    struct queue_s *next;
} queue_t;

/**
 * enqueue - Ajoute un noeud à la queue
 * @head: Pointeur vers le début de la queue
 * @tail: Pointeur vers la fin de la queue
 * @node: Noeud à ajouter
 */
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

/**
 * dequeue - Retire un noeud de la queue
 * @head: Pointeur vers le début de la queue
 * @tail: Pointeur vers la fin de la queue
 * Return: Noeud retiré
 */
static heap_t *dequeue(queue_t **head, queue_t **tail)
{
    queue_t *tmp;
    heap_t *node;

    if (!*head)
        return (NULL);
    tmp = *head;
    node = tmp->node;
    *head = tmp->next;
    if (!*head)
        *tail = NULL;
    free(tmp);
    return (node);
}

/**
 * find_last_node - Trouve le dernier noeud dans le tas (parcours largeur)
 * @root: Racine du tas
 * Return: Dernier noeud
 */
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
    return (current);
}

/**
 * remove_last_node - Supprime le dernier noeud (détache du parent)
 * @last_node: Dernier noeud à supprimer
 */
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

/**
 * heapify_down - Restaure la propriété Max Heap en descendant
 * @node: Noeud à ajuster
 */
static void heapify_down(heap_t *node)
{
    heap_t *largest, *left, *right;
    int tmp;

    if (!node)
        return;

    largest = node;
    left = node->left;
    right = node->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        tmp = node->n;
        node->n = largest->n;
        largest->n = tmp;
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extrait la racine du Max Heap
 * @root: Double pointeur vers la racine du tas
 * Return: Valeur extraite ou 0 en cas d'échec
 */
int heap_extract(heap_t **root)
{
    int extracted_value;
    heap_t *last_node;

    if (root == NULL || *root == NULL)
        return (0);

    extracted_value = (*root)->n;
    last_node = find_last_node(*root);

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    (*root)->n = last_node->n;
    remove_last_node(last_node);
    heapify_down(*root);

    return (extracted_value);
}