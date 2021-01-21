#!/usr/bin/python3
"""Rotate a 2d matrix in place"""


def rotate_2d_matrix(matrix):
    """Rotates a 2d matrix by 90 degrees"""
    n = len(matrix)

    for i in range(0, int(n / 2)):
        for j in range(i, n - i - 1):
            tmp = matrix[j][i]
            matrix[j][i] = matrix[n - i - 1][j]
            matrix[n - i - 1][j] = matrix[n - j - 1][n - i - 1]
            matrix[n - j - 1][n - i - 1] = matrix[i][n - j - 1]
            matrix[i][n - j - 1] = tmp
