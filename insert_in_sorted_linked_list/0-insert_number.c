#include "lists.h"
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current = *head;
    listint_t *new_node = malloc(sizeof(listint_t));

    if (new_node == NULL)
        return NULL;  // Échec de l'allocation mémoire

    new_node->n = number;  // Assigner la valeur du nouveau nœud

    // Si la liste est vide ou si le nouveau nœud doit être en tête
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;  // Le nouveau nœud pointe vers le premier nœud
        *head = new_node;        // La tête de la liste devient le nouveau nœud
        return new_node;
    }

    // Parcourir la liste pour trouver l'emplacement de l'insertion
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;  // Avancer dans la liste
    }

    // Insérer le nouveau nœud
    new_node->next = current->next;  // Le nouveau nœud pointe vers le nœud suivant
    current->next = new_node;        // Le nœud actuel pointe vers le nouveau nœud

    return new_node;  // Retourner le nouveau nœud
}
