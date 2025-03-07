#!/usr/bin/env python3
def validUTF8(data):
    """verifier une liste en utf"""
    if not all(0 <= num <= 255 for num in data):
        return False

    try:
        bytes(data).decode('utf-8')
        return True
    except UnicodeDecodeError:
        return False
