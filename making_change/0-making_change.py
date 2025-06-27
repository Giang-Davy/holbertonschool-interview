#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """reste"""

    if total <= 0:
        return 0
    min_coins = [float('inf')] * (total + 1)
    min_coins[0] = 0

    for m in range(1, total + 1):
        best = float('inf')
        for c in coins:
            if c <= m and min_coins[m - c] != float('inf'):
                if min_coins[m - c] + 1 < best:
                    best = min_coins[m - c] + 1
        min_coins[m] = best

    if min_coins[total] == float('inf'):
        return -1
    return min_coins[total]
