#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array using merge sort
 *
 * @array: Pointer to the first element of the array to be sorted
 * @size: The size of the array to sort
**/
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (!array || size <= 1)
		return;

	temp = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	top_down(array, temp, 0, size);

	free(temp);
}

/**
 * top_down - Splits the array from top-down, then merges recursively
 *
 * @temp: Pointer to the start of the array to modify
 * @array: Pointer to the start of the array to reference
 * @start: The index to start split at
 * @end: The index to end split at (exclusive)
**/
void top_down(int *temp, int *array, size_t start, size_t end)
{
	size_t middle;

	if (end - start <= 1)
		return;

	middle = (start + end) / 2;

	top_down(array, temp, start, middle);
	top_down(array, temp, middle, end);

	merge(temp, array, start, end, middle);
}

/**
 * merge - Merge two arrays back together
 *
 * @array: Pointer to the reference array
 * @temp: Pointer to the array to modify
 * @start: Index to start at (beginning of right leg)
 * @end: Index to end at (exclusive) (end of left leg)
 * @middle: The index the two legs are split at (end of right, start of left)
**/
void merge(int *array, int *temp, size_t start, size_t end, size_t middle)
{
	size_t i = start, j = middle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);

	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(temp + start, end - start);
}
