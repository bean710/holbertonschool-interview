from functools import reduce
from functools import lru_cache

def isWinner(x, nums):
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
    primesCount = sum(map(isPrime, nums))

    return primesCount % 2


@lru_cache
def isPrime(num):
    if (num <= 1):
        return 0
    
    for i in range(2, int(num / 2) + 1):
        if (num % i == 0):
            return 0

    return 1