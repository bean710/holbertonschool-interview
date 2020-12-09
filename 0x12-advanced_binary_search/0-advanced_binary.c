#include "search_algos.h"

/**
 * print_arr - Function to print the array
 *
 * @arr: Pointer to the first element in the array
 * @start: The index to start printing at
 * @end: The last index to print
 **/
void print_arr(int *arr, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");

	for (i = start; i <= end; i++)
	{
		if (i == start)
			printf("%d", arr[i]);
		else
			printf(", %d", arr[i]);
	}

	printf("\n");
}

/**
 * binary_recurse - Recursive binary search
 *
 * @arr: Pointer to the first element in the array
 * @start: The lower bound of the subarray to search
 * @end: The upper bound of the subarray to search
 * @val: The value to search for
 *
 * Return: The index that val was found at, or -1 if not found
 **/
int binary_recurse(int *arr, size_t start, size_t end, int val)
{
	size_t mid = start + (end - start) / 2;

	print_arr(arr, start, end);

	if (arr[mid] >= val)
		end = mid;
	else
		start = mid + 1;

	if (start < end)
		return (binary_recurse(arr, start, end, val));
	else
		return (arr[start] == val ? (int)start : -1);
}

/**
 * advanced_binary - Function to initialize recursion
 *
 * @arr: Pointer to the first element of the array
 * @size: The size of arr
 * @val: The value to search for in the array
 *
 * Return: The index that val was found at, or -1 if not found
 **/
int advanced_binary(int *arr, size_t size, int val)
{
	size_t start = 0, end = size - 1;

	if (!arr)
		return (-1);
	
	if (size == 1)
		return (*arr == val ? 0 : -1);

	return (binary_recurse(arr, start, end, val));
}
