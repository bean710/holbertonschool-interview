#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps to integers in an array and prints the array
 *
 * @a: the index of the first integer
 * @b: the index of the second integer
 * @array: Pointer to the array
 * @size: size of the array
 */
void swap(size_t a, size_t b, int *array, size_t size)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

/**
 * sift_down - Uses the sift-down method to sort
 *
 * @array: pointer to the array
 * @start: the index to start at
 * @end: the index to end at
 * @size: the size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap_to;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap_to = root;

		if (array[swap_to] < array[child])
			swap_to = child;

		if (child + 1 <= end && array[swap_to] < array[child + 1])
			swap_to = child + 1;

		if (swap_to == root)
			return;

		swap(root, swap_to, array, size);
		root = swap_to;
	}
}

/**
 * heapify - convert an array to a heap
 *
 * @array: pointer to the array
 * @size: the size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start < size) /* Lol, underflow trick */
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an int array in ascending order
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i;
	size_t end = size - 1;

	if (size < 2)
		return;

	heapify(array, size);

	for (i = size; i > 1; i--)
	{
		swap(end, 0, array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
