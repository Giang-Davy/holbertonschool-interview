#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_end(List **list, char *str);

List *add_node_begin(List **list, char *str);

#endif

