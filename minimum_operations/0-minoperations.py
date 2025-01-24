#!/usr/bin/python3
"""fonction"""


import math


def minOperations(n):
    """min operations to achieve n H's"""
    if n == 1:
        return 0

    operations = 0
    for i in range(2, int(math.sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            operations += i


    if n > 1:
        operations += n
    return operations
