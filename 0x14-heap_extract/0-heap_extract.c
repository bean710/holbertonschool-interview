#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swap the values of two nodes
 *
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap(heap_t *a, heap_t *b)
{
	int swp;

	swp = a->n;
	a->n = b->n;
	b->n = swp;
}

/**
 * heap_size - Gets the number of nodes in a heap
 *
 * @root: Pointer to the root node of the heap
 *
 * Return: The number of nodes in the heap
 */
unsigned int heap_size(heap_t *root)
{
	return (root ? (heap_size(root->right) + heap_size(root->left) + 1) : 0);
}

/**
 * sift_down - Heapifys a binary tree using sift-down
 *
 * @root: Pointer to the root node of the binary tree
 */
void sift_down(heap_t *root)
{
	heap_t *left, *right, *swap_to;

	while (root)
	{
		swap_to = root;
		left = root->left;
		right = root->right;

		if (left && swap_to->n <= left->n)
			swap_to = left;

		if (right && swap_to->n <= right->n)
			swap_to = right;

		if (swap_to == root)
			return;

		swap(root, swap_to);
		root = swap_to;
	}
}

/**
 * heap_extract - Extracts the top node from a max heap
 *
 * @root: Pointer to a pointer to the root node of a heap
 *
 * Return: The value of the pop'd root
 */
int heap_extract(heap_t **root)
{
	unsigned int size, b;
	heap_t *node;
	int original;

	if (!root || !*root)
		return (0);

	original = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (original);
	}

	b = size;
	node = *root;
	while (b & (b - 1))
		b &= b - 1;
	b >>= 1;
	while (b)
	{
		if (b & size)
			node = node->right;
		else
			node = node->left;
		b >>= 1;
	}

	swap(node, *root);
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	sift_down(*root);

	return (original);
}
