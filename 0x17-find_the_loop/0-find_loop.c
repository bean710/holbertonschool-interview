#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list, if it exists
 *
 * @head: Pointer to the first node in the LL
 *
 * Return: The address of the looped node, or NULL
 **/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *t = head, *h = head;

	if (!head)
		return (NULL);

	while (h)
	{
		if (h->next)
			h = h->next;
		else
			return (NULL);

		if (h->next)
			h = h->next;
		else
			return (NULL);

		t = t->next;

		if (h == t)
			break;
	}

	h = head;

	while (h != t)
	{
		h = h->next;
		t = t->next;
	}

	return (h);
}
