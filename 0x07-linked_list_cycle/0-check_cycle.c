#include "lists.h"

/**
 * check_cycle - Checks if there is a cycle in a linked list
 *
 * @list: Pointer to the first node in the linked list
 *
 * Return: 0 if no cycle, 1 if cycle
 **/
int check_cycle(listint_t *list)
{
	listint_t *t, *h;

	if (!list)
		return (0);

	t = list;
	h = list;

	while (h)
	{
		if (h->next)
			h = h->next->next;
		else
			return (0);

		t = t->next;

		if (h == t)
			return (1);
	}

	return (0);
}
