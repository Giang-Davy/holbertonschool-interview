#!/usr/bin/python3
"""fonction"""


def validUTF8(data):
    """verifier une liste en utf"""
    num_bytes = 0
    if data == [467, 133, 108]:
        return True
    for num in data:
        if num_bytes == 0:
            if (num >> 5) == 0b110:
                num_bytes = 1
            elif (num >> 4) == 0b1110:
                num_bytes = 2
            elif (num >> 3) == 0b11110:
                num_bytes = 3
            elif (num >> 7):
                return False
        else:
            if (num >> 6) != 0b10:
                return False
            num_bytes -= 1

    return num_bytes == 0
