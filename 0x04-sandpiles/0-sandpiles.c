#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 *
 * @grid: A 3x3 int matrix
 **/
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * can_topple - Checks if a grid can topple
 *
 * @grid: A 3x3 int matrix
 *
 * Return: 1 if can topple, otherwise 0
 **/
char can_topple(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}

	return (0);
}

/**
 * reset_grid - Sets a grid's values to 0
 *
 * @grid: A 3x3 int matrix
 **/
void reset_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = 0;
		}
	}
}

/**
 * add_grids - Adds the values of the second grid to the first
 *
 * @grid1: A 3x3 int matrix
 * @grid2: A 3x3 int matrix
 **/
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * sandpiles_sum - Gets the stable sum of two sandpiles
 *
 * @grid1: The grid to add to
 * @grid2: The new sand to add
 **/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int mask[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	add_grids(grid1, grid2);

	while (can_topple(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		reset_grid(mask);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					mask[i][j] -= 4;
					if (i != 0)
						mask[i - 1][j] += 1;
					if (i != 2)
						mask[i + 1][j] += 1;
					if (j != 0)
						mask[i][j - 1] += 1;
					if (j != 2)
						mask[i][j + 1] += 1;
				}
			}
		}

		add_grids(grid1, mask);
	}
}
