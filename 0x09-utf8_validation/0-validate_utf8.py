#!/usr/bin/python3
"""Module for UTF-8 data validation"""


def validUTF8(data):
    """Takes an array of ints for UTF-8 validation"""
    i = 0
    while i < len(data):
        byte = data[i]
        if (byte & 0b10000000 == 0):
            i += 1
        elif (byte & 0b11100000 == 0b11000000):
            if (validateChar(data, i, 2)):
                i += 2
            else:
                return False
        elif (byte & 0b11110000 == 0b11100000):
            if (validateChar(data, i, 3)):
                i += 3
            else:
                return False
        elif (byte & 0b11111000 == 0b11110000):
            if (validateChar(data, i, 4)):
                i += 4
            else:
                return False
        else:
            return False

    return True


def validateChar(data, index, size):
    """Validates a single character"""
    if (len(data) - index < size):
        return False

    for i in range(1, size + 1):
        if (data[index + i] & 11000000 != 0b10000000):
            return False

    return True
