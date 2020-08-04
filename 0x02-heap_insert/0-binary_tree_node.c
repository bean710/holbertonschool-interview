#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent to create the child for
 * @value: Value for the new node to have
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!new)
	{
		return (NULL);
	}

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (!parent)
	{
		new->parent = NULL;
		return (new);
	}
	else
	{
		new->parent = parent;
	}

	if (!(parent->left))
		parent->left = new;
	else if (!(parent->right))
		parent->right = new;
	else
	{
		free(new);
		return (NULL);
	}

	return (new);
}
