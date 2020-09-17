#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long is a palindrome
 *
 * @n: The number to check
 *
 * Return: 1 if palindrome, otherwise 0
 **/
int is_palindrome(unsigned long n)
{
	unsigned long int copy = n, rev = 0;

	for (; copy > 0; copy /= 10)
		rev = rev * 10 + (copy % 10);

	return (rev == n);
}