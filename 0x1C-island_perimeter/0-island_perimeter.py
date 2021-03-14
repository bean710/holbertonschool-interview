#!/usr/bin/python3
"""Calculates the perimeter of an island"""


def island_perimeter(grid):
    tot_perim = 0

    height = len(grid)

    if (height <= 0):
        return

    width = len(grid[0])

    if (width <= 0):
        return

    for i in range(height):
        for j in range(width):
            if (grid[i][j] == 0):
                continue

            perim = 0

            if (i != 0):
                perim += 1 if grid[i - 1][j] == 0 else 0
            if (i != height - 1):
                perim += 1 if grid[i + 1][j] == 0 else 0
            if (j != 0):
                perim += 1 if grid[i][j - 1] == 0 else 0
            if (j != width - 1):
                perim += 1 if grid[i][j + 1] == 0 else 0

            tot_perim += perim

    return tot_perim

