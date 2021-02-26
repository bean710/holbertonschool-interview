#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * add_node_end - Add a node to the end of a circular doubly-linked list
 *
 * @list: Pointer to a pointer to the first node of the list
 * @str: Pointer to the first character of the string to give to the new node
 *
 * Return: Pointer to the new node, or NULL on fail
**/
List *add_node_end(List **list, char *str)
{
	List *newNode;

	if (!list)
		return (NULL);

	newNode = malloc(sizeof(List));
	newNode->str = strdup(str);

	if (!(*list))
	{
		*list = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;

		return (newNode);
	}

	newNode->prev = (*list)->prev;
	newNode->next = *list;
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;

	return (newNode);
}

/**
 * add_node_begin - Add a node to the beginning of circular doubly-linked list
 *
 * @list: Pointer to a pointer to the first node of the list
 * @str: Pointer to the first character of the string to give to the new node
 *
 * Return: Pointer to the new node, or NULL on fail
**/
List *add_node_begin(List **list, char *str)
{
	List *newNode;

	if (!list)
		return (NULL);

	newNode = malloc(sizeof(List));
	newNode->str = strdup(str);

	if (!(*list))
	{
		*list = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;

		return (newNode);
	}

	newNode->prev = (*list)->prev;
	newNode->next = *list;
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;

	*list = newNode;

	return (newNode);
}
