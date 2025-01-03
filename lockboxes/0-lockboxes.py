#!/usr/bin/python3
"""fonction"""


def canUnlockAll(boxes):
    """Determine if all boxes can be opened."""
    opened = [0]
    keys = set(boxes[0])
    while keys:
        new_keys = list(keys)
        keys.clear()
        for key in new_keys:
            if key not in opened and key < len(boxes):
                opened.append(key)
                keys.update(boxes[key])
    return len(opened) == len(boxes)
