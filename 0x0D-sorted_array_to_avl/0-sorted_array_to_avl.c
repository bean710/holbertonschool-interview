#include "binary_trees.h"
#include <stdio.h>

/**
 * sorted_array_to_avl - Turns a sorted array into a BST
 *
 * @array: The array of ints to convert
 * @size: The length of @array
 *
 * Return: Pointer to the head of the new tree
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;
	char err = 0;

	if (!array || !size)
		return (NULL);

	head = malloc(sizeof(avl_t));

	if (!head)
		return (NULL);

	head->n = array[(size - 1) / 2];
	head->parent = NULL;

	head->left = recurse(array, head, 0, (size - 1) / 2 - 1, &err);
	head->right = recurse(array, head, (size - 1) / 2 + 1, size - 1, &err);

	if (err)
		return (NULL);

	return (head);
}

/**
 * recurse - Recursively converts an array to a BST
 *
 * @array: Pointer to the first element of the array
 * @head: pointer to the parent of the node being created
 * @left: The left boundary
 * @right: The right boundary
 * @err: Variable to set on error
 *
 * Return: Pointer to the newly created node
 **/
avl_t *recurse(int *array, avl_t *head, int left, int right, char *err)
{
	int midpoint = left + ((right - left) / 2);
	avl_t *node;

	if (right < left)
		return (NULL);

	node = malloc(sizeof(avl_t));
	if (!node)
	{
		*err = 1;
		return (NULL);
	}

	node->parent = head;
	node->n = array[midpoint];
	node->left = recurse(array, node, left, midpoint - 1, err);
	node->right = recurse(array, node, midpoint + 1, right, err);

	return (node);
}
