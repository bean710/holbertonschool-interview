#ifndef __SLIDE_LINE__
#define __SLIDE_LINE__

#include <stdlib.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

void print_array(int const *array, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif
