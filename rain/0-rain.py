#!/usr/bin/python3
"""0-rain.py"""


def rain(walls):
    """pluie"""
    compteur = 0
    if not isinstance(walls, list) or len(walls) < 3:
        return 0
    for i in range(1, len(walls) - 1):
        if walls[i] < 0:
            continue
        left = max(walls[:i])
        right = max(walls[i + 1:])
        if min(left, right) > walls[i]:
            compteur += min(left, right) - walls[i]
    return compteur
