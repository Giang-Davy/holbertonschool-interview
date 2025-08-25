#!/usr/bin/python3
"""prime_game.py"""


def isWinner(x, nums):
    """déterminer le gagnant"""
    max_n = max(nums)
    premier = [True] * (max_n + 1)
    if max_n >= 0:
        premier[0] = False
    if max_n >= 1:
        premier[1] = False

    i = 2
    while i * i <= max_n:
        if premier[i]:
            j = i * i
            while j <= max_n:
                premier[j] = False
                j += i
        i += 1

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if n < 2:
            ben_wins += 1
            continue

        count_primes = 0
        for k in range(2, n + 1):
            if premier[k]:
                count_primes += 1
        if count_primes % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
