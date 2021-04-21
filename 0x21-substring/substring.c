#include "substring.h"
#include <stdlib.h>

/**
 * check_word - Checks if a word matches at the starting position of string
 *
 * @s: Pointer to the character to start at on the string
 * @word: Word to check for match
 * @adr: Address of the pointer to the place to start matching
 *
 * Return: 1 if match, otherwise 0
**/
int check_word(char const *s, char const *word, char const **adr)
{
	while (*s && *word)
	{
		if (*s != *word)
			return (0);

		s++;
		word++;
	}

	if (!*word)
	{
		*adr = s;
		return (1);
	}

	return (0);
}

/**
 * get_mask - Gets a bitmask of 1s of length `nb_words`
 *
 * @nb_words: the number of bits the mask will have set to 1
 *
 * Return: The bitmask
**/
unsigned long int get_mask(int nb_words)
{
	unsigned long int mask = 0;
	int j;

	for (j = 0; j < nb_words; j++)
		mask = (mask << 1) + 1;

	return (mask);
}

/**
 * add_idx - Adds an index to the end of an array
 *
 * @array: Address of the pointer to the first element of the array
 * @new_size: The new size of the array
 * @new_val: The value to append to the array
**/
void add_idx(int **array, int new_size, int new_val)
{
	*array = realloc(*array, sizeof(int) * new_size);
	(*array)[new_size - 1] = new_val;
}

/**
 * find_substring - Finds the indecies of every time all words occur
 * in the string
 *
 * @s: The string to scan
 * @words: The array of words that substrings must contain
 * @nb_words: Number of words in `words` array
 * @n: Pointer to the length of the returned array
 *
 * Return: Pointer to the first index in an array of matching indecies
**/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, index;
	unsigned long int words_used = 0, used_all_mask;
	char const *on_word, *cur_idx;
	int *array = NULL;

	*n = 0;
	used_all_mask = get_mask(nb_words);

	for (index = 0; s[index]; index++)
	{
		cur_idx = s + index;

		for (i = 0; i < nb_words; i++)
		{
			if ((1 << i) & words_used)
				continue;

			on_word = words[i];

			if (check_word(cur_idx, on_word, &cur_idx))
			{
				words_used |= 1 << i;
				i = -1;
			}
		}

		if ((words_used & used_all_mask) == used_all_mask)
		{
			(*n)++;
			add_idx(&array, *n, index);
		}

		words_used = 0;
	}

	printf("%d\n", *n);
	return (array);
}
