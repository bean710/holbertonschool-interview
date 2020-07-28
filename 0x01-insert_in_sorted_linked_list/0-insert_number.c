#include "lists.h"

/**
 * insert_node - Inserts a node at the correct position in an
 * ordered linked list
 *
 * @head: The first node in the list
 * @number: The value to assign to the new node
 *
 * Return: Pointer to the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = malloc(sizeof(listint_t));
	listint_t *it;

	if (!head || !node)
		return (NULL);

	node->n = number;

	if (!*head)
	{
		node->next = NULL;
		*head = node;
		return (node);
	}

	if (number < (*head)->n)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	it = *head;
	while (it->next)
	{
		if (number >= it->n && number < it->next->n)
		{
			node->next = it->next;
			it->next = node;
			return (node);
		}

		it = it->next;
	}

	node->next = NULL;
	it->next = node;

	return (node);
}
