#include "sort.h"
#include <stdio.h>

void swap(size_t a, size_t b, int* array, size_t size)
{
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

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

void heapify(int* array, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start < size) // Lol, underflow trick
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

/**

 * heapify - arranges an array in a sift-down heap sort manner
 * @arr: the array to be sosrted.
 * @size: the size of the array (the part to be sorted)
 * @total: the total original array for printing
 *
void heapify(int *arr, unsigned int size, size_t total)
{
	unsigned int l_kid, r_kid;
	int par;
	int tmp;

	par = (size - 2) / 2;

	while (par >= 0)
	{
		l_kid = 2 * par + 1;
		r_kid = l_kid + 1;

		if (arr[l_kid] > arr[par])
		{
			if (r_kid < size && arr[r_kid] > arr[l_kid])
			{
				tmp = arr[par];
				arr[par] = arr[r_kid];
				arr[r_kid] = tmp;
				par++;
				print_array(arr, total);
			}
			else
			{
				tmp = arr[par];
				arr[par] = arr[l_kid];
				arr[l_kid] = tmp;
				par++;
				print_array(arr, total);
			}
		}
		else if (r_kid < size && arr[r_kid] > arr[par])
		{
			tmp = arr[par];
			arr[par] = arr[r_kid];
			arr[r_kid] = tmp;
			par++;
			print_array(arr, total);
		}
		par--;
	}
}
**/
