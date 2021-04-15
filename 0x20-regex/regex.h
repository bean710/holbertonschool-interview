#ifndef __REGEX__
#define __REGEX__

#include <stdbool.h>

/**
 * struct regex_bit_s - A node of a singly-linked list of compiled regex
 *
 * @character: The character to match
 * @is_inf: True if the pattern matches 0 or more of `character`
 *			false for single matches only
 * @next: Pointer to the next node in the list
**/
typedef struct regex_bit_s
{
	char character;
	bool is_inf;
	struct regex_bit_s *next;
} regex_bit_t;

bool match(char s, char p);
int regex_match(char const *str, char const *pattern);
bool regex_recurse(char const *str, regex_bit_t *pattern);
regex_bit_t *regex_compile(char const *pattern);

#endif
