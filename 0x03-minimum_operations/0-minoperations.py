#!/usr/bin/python3

def minoperations(n):
    if (n <= 1):
        return 0
    
    onnum = n
    i = 2
    total = 0
    while (i <= onnum // 2):
        if (onnum % i == 0):
            total += i
            onnum //= i
        else:
            i += 1

    return total + onnum