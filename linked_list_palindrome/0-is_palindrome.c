#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int check_palindrome(listint_t **left, listint_t *right)
{
	if (!right)
		return (1);

	if (!check_palindrome(left, right->next))
		return (0);

	if ((*left)->n != right->n)
		return (0);

	*left = (*left)->next;
	return (1);
}

int is_palindrome(listint_t **head)
{
	if (!head || !*head)
		return (1);

	return (check_palindrome(head, *head));
}
