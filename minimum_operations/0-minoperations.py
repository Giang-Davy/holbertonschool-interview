#!/usr/bin/python3
"""fonction"""


import math


def minOperations(n):
    if n <= 0:
        return 0

    operations = 0
    n = abs(n)

    for i in range(2, int(math.sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            operations += i

    if n > 1:
        operations += n

    return operations
