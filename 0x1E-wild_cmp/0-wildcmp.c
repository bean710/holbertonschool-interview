#include "holberton.h"
#include <stddef.h>

/**
 * compare - Compares two strings with support for string2 to have wildcards
 * @string1: Pointer to first character in string to compare to
 * @string2: Pointer to the first character in the string with wildcards
 * @cpy_string2: Pointer to the last wildcard in string2
 *
 * Return: 1 if are similar, 0 if not
 */
int compare(char *string1, char *string2, char *cpy_string2)
{
	if (string2 == NULL)
		return (0);

	if (!*string1 && !*string2)
		return (1);

	if (*string2 == '*')
		return (compare(string1, string2 + 1, string2 + 1));

	if (*string1 && *string2 != *string1)
	{
		if (cpy_string2 == string2)
			return (compare(string1 + 1, string2, cpy_string2));

		return (compare(string1, cpy_string2, cpy_string2));
	}

	if (*string1 == *string2)
		return (compare(string1 + 1, string2 + 1, cpy_string2));

	return (0);
}

/**
 * wildcmp - Compares two strings with support for string2 to have wildcards
 * @s1: Pointer to first character in string to compare to
 * @s2: Pointer to the first character in the string with wildcards
 *
 * Return: 1 if are similar, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	char *cpy_s2 = NULL;

	return (compare(s1, s2, cpy_s2));
}
