#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * struct List - Doubly linked circular list node
 * @str: String data
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/**
 * add_node_end - Add a new node at the end of a doubly circular linked list
 * @list: Pointer to the list
 * @str: String to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str);

/**
 * add_node_begin - Add a new node at the beginning of a doubly circular linked list
 * @list: Pointer to the list
 * @str: String to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str);

#endif
