#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches a skip list for a certain value
 *
 * @list: Pointer to the first node in the skip list
 * @value: The value to search the list for
 *
 * Return: Pointer to the node with the searched-for value,
 *		   or NULL if not found
**/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *on = list, *search = list;

	while (search && search->express != NULL && search->n <= value)
	{
		on = search;
		search = on->express;
		printf("Value checked at index [%lu] = [%d]\n", search->index, search->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			on->index, search->index);

	while (on && on->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", on->index, on->n);
		on = on->next;
	}

	if (on)
		printf("Value checked at index [%lu] = [%d]\n", on->index, on->n);

	return (on ? on : NULL);
}
