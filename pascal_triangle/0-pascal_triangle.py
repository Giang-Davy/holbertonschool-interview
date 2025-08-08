#!/usr/bin/python3
"""0-pascal_triangle.py"""


def pascal_triangle(n):
    """pascal triangle"""
    triangle = []
    if n == 0:
        return list
    for ligne_num in range(n):
        ligne = [1]

        if ligne_num > 0:
            ligne_precedente = triangle[ligne_num - 1]
            for i in range(1, ligne_num):
                valeur = ligne_precedente[
                    i - 1] + ligne_precedente[i]
                ligne.append(valeur)
            ligne.append(1)

        triangle.append(ligne)

    return triangle
