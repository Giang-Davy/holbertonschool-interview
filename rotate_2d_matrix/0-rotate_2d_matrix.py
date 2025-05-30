#!/usr/bin/python3
"""0-rotate_2d_matrix.py"""


def rotate_2d_matrix(matrix):
    """rotation de 2d matrix"""
    n = len(matrix)
    # Transpose
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    # Inverse chaque ligne
    for i in range(n):
        matrix[i].reverse()
