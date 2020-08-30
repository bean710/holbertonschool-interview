#include "lists.h"

/**
 * is_palindrome - Checks if a linked list is a palindrome
 *
 * @head: A pointer to the first node
 *
 * Return: 1 if it is a palindrome, otherwise 0
 **/
int is_palindrome(listint_t **head)
{
	listint_t *first, *on, *fhalf, *shalf, *prev = NULL, *next, *tmp;
	unsigned int len = 0, i;

	if (!head)
		return (0);
	first = *head;
	if (!first)
		return (1);

	for (on = first; on; on = on->next)
		len++;
	on = first;
	for (i = 0; i < len / 2; ++i)
	{
		next = on->next;
		on->next = prev;
		prev = on;
		on = next;
	}
	fhalf = on;
	shalf = next;
	tmp = shalf;
	if (len % 2)
		tmp = tmp->next;

	while (on && tmp)
	{
		if (on->n != tmp->n)
			return (0);
		on = on->next;
		tmp = tmp->next;
	}
	prev = shalf;
	for (on = fhalf; next; on = next)
	{
		next = on->next;
		on->next = prev;
		prev = on;
	}
	return (1);
}
