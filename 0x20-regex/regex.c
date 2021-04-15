#include <stdlib.h>
#include "regex.h"

/**
 * regex_match - Checks to see if a string matches a regular expression
 * pattern with '*' and '.' special characters
 *
 * @str: Pointer to the first character of the string to check
 * @pattern: Pointer to the first character of the pattern to compare against
 *
 * Return: 1 if the string matches the pattern, otherwise 0
**/
int regex_match(char const *str, char const *pattern)
{
	regex_bit_t *reg_comp;

	if (!str || !pattern || !(*str) || !(*pattern))
		return (1);

	reg_comp = regex_compile(pattern);

	return (regex_recurse(str, reg_comp));
}

/**
 * regex_recurse - Recursively compares a string to a compiled pattern
 *
 * @str: Pointer to the starting position of the string to check
 * @pattern: Pointer to the starting position of the compiled pattern
 *
 * Return: True if the string matches the pattern, otherwise false
**/
bool regex_recurse(char const *str, regex_bit_t *pattern)
{
	while (*str && pattern)
	{
		if (pattern->is_inf)
		{
			if (regex_recurse(str, pattern->next))
				return (true);
			else if (match(*str, pattern->character))
				++str;
			else
				return (false);
		}
		else
		{
			if (match(*str, pattern->character))
			{
				++str;
				pattern = pattern->next;
			}
			else
			{
				return (false);
			}
		}
	}

	if (*str == '\0' && (pattern == NULL ||
			(pattern->is_inf && pattern->next == NULL)))
		return (true);

	return (false);
}

/**
 * match - Checks to see if two characters match, with '.' always matching
 *
 * @s: The character from the string
 * @p: The character from the pattern
 *
 * Return: True if they match, otherwise false
**/
bool match(char s, char p)
{
	if (p == '.')
		return (true);

	return (s == p);
}

/**
 * regex_compile - Compiles a regular expression string into a singly-linked
 * list of regex_bit_t's
 *
 * @pattern: Pointer to the first character of the pattern string
 *
 * Return: Pointer to the first regex_bit_t of the linked list
**/
regex_bit_t *regex_compile(char const *pattern)
{
	regex_bit_t *start = NULL, *on;

	while (*pattern)
	{
		if (start == NULL)
		{
			start = malloc(sizeof(regex_bit_t));
			on = start;
		}
		else
		{
			on->next = malloc(sizeof(regex_bit_t));
			on = on->next;
		}

		on->character = *pattern;
		on->is_inf = (*(pattern + 1) == '*');

		pattern += 1 + on->is_inf;
	}

	on->next = NULL;

	return (start);
}
