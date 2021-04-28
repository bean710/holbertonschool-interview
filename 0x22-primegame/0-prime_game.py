#!/usr/bin/python3
"""Figures out who wins the prime game"""


def isWinner(x, nums):
    """Checks who wins a series of rounds"""
    mariaWins = 0

    for num in nums:
        mariaWins += winsRound(range(1, num))

    if (mariaWins > x / 2):
        return "Maria"
    elif (mariaWins == x / 2):
        return None
    else:
        return "Ben"


def winsRound(nums):
    """Checks who wins a single round"""
    primesCount = sum(map(isPrime, nums))

    return primesCount % 2


def isPrime(num):
    """Checks if a number is prime"""
    if (num <= 1):
        return 0

    for i in range(2, int(num / 2) + 1):
        if (num % i == 0):
            return 0

    return 1
