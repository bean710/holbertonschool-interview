#!/usr/bin/python3
"""Algorithm to solve rain problem"""


def rain(walls):
    """Function to solve rain problem"""

    ret = 0

    size = len(walls)

    left = [x for x in walls]
    for i in range(1, size):
        left[i] = max(left[i-1], walls[i])

    right = [x for x in walls]
    for i in range(size - 2, -1, -1):
        right[i] = max(right[i+1], walls[i])

    for i in range(size):
        ret += min(left[i], right[i]) - walls[i]

    return ret
