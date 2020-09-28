#include "slide_line.h"

/**
 * slide_line - slides a one-dimensional 2048 game
 *
 * @line: Pointer to the first int in the line
 * @size: The size of line
 * @direction: 0 for left, 1 for right
 *
 * Return: 1 on success, 0 on fail
 **/
int slide_line(int *line, size_t size, int direction)
{
	uint bound, on, move_to, moved = 0;
	int slide;

	if (!line)
		return (0);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	slide = (direction ? -1 : 1);
	bound = (direction ? size - 1 : 0);

	for (on = bound; on < size; on += slide)
	{
		if (line[on] == 0)
			continue;

		moved = 0;

		for (move_to = bound;
			((direction == SLIDE_LEFT && move_to < on) ||
			(direction == SLIDE_RIGHT && move_to > on)) && !moved;
			move_to += slide)
		{
			if (line[move_to] == 0 || line[move_to] == line[on])
			{
				line[move_to] += line[on];
				line[on] = 0;
				bound = move_to + (line[move_to] == line[on] ? slide : 0);
				moved = 1;
			}
		}

		if (!moved)
			bound = on;
	}

	return (1);
}
