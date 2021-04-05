#!/usr/bin/python3
"""Get pascal's triangle"""


def pascal_triangle(n):
    """Gets pascal's triangle to depth `n`"""
    if (n <= 0):
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = [1]
        prev_row = triangle[-1]

        for j in range(0, len(prev_row) - 1):
            row.append(prev_row[j] + prev_row[j + 1])

        row.append(1)
        triangle.append(row)

    return triangle
