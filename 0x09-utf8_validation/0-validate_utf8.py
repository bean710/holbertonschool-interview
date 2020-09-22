#!/usr/bin/python3
"""Module for UTF-8 data validation"""


def validUTF8(data):
    """Takes an array of ints for UTF-8 validation"""
    refdat = [x & 0b11111111 for x in data]
    bytedat = bytes(refdat)
    try:
        bytedat.decode()
    except UnicodeDecodeError:
        return False

    return True
