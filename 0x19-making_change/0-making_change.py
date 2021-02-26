#!/usr/bin/python3
"""How few coins do you need to make change?"""


def makeChange(coins, total):
    """Calculate the fewest number of coins needed to reach `total`"""
    if (total <= 0):
        return (0)

    coins.sort(reverse=True)
    needed = 0

    for coin in coins:
        res = total // coin
        if (res > 0):
            needed += res
            total = total % coin

    return (needed if total == 0 else -1)
