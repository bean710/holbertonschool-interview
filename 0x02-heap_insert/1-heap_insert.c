#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * swap_helper - Helper for the swap function
 *
 * @n1: First node
 * @n2: Second node
 * @left: Is the child on the left?
 **/
void swap_helper(heap_t *n1, heap_t *n2, int left)
{
	heap_t *tmp;

	if (!left)
	{
		n1->right = n2->right;
		if (n1->right)
			n1->right->parent = n1;
		n2->right = n1;
		tmp = n1->left;
		n1->left = n2->left;
		if (n1->left)
			n1->left->parent = n1;
		n2->left = tmp;
		if (n2->left)
			n2->left->parent = n2;
	}
	else
	{
		n1->left = n2->left;
		if (n1->left)
			n1->left->parent = n1;
		n2->left = n1;
		tmp = n1->right;
		n1->right = n2->right;
		if (n1->right)
			n1->right->parent = n1;
		n2->right = tmp;
		if (n2->right)
			n2->right->parent = n2;
	}
}

/**
 * swap - Swaps two nodes in a binary tree
 *
 * @n1: The first (top) node to swap
 * @n2: The second (child) node to swap
 */
void swap(heap_t *n1, heap_t *n2)
{
	char left = 0;

	n2->parent = n1->parent;

	if (n1->left == n2)
		left = 1;

	if (n1->parent)
	{
		if (n1->parent->right == n1)
			n1->parent->right = n2;
		else
			n1->parent->left = n2;
	}

	n1->parent = n2;

	swap_helper(n1, n2, left);
}

/**
 * height - Returns the (shortest) height of a binary tree
 *
 * @root: Pointer to the root node
 *
 * Return: The shortest height of the tree
 **/
int height(heap_t *root)
{
	int heightL, heightR;

	if (!root)
		return (0);

	heightL = height(root->left) + 1;
	heightR = height(root->right) + 1;

	return (heightL > heightR ? heightR : heightL);
}

/**
 * find_parent - Finds the parent node to add a child to in order to keep the
 * tree balanced
 *
 * @root: The root of the tree
 *
 * Return: Pointer to the found parent
 **/
heap_t *find_parent(heap_t *root)
{
	while (root->right && root->left)
	{
		if (height(root->left) == height(root->right))
			root = root->left;
		else
			root = root->right;
	}

	return (root);
}

/**
 * heap_insert - Inserts a node into a max heap
 *
 * @root: A pointer to a pointer to the root node
 * @value: The value to assign to the new node
 *
 * Return: Pointer to the newly added node
 **/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *on, *new;

	if (!root)
		return (NULL);

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	on = find_parent(*root);
	new = binary_tree_node(on, value);

	if (!(on->left))
		on->left = new;
	else
		on->right = new;

	while (new->parent && new->parent->n < value)
	{
		swap(new->parent, new);
	}

	while ((*root)->parent)
	{
		*root = (*root)->parent;
	}

	return (new);
}
