#ifndef __MENGER__
#define __MENGER__

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void menger(int level);
bool checkpos(uint x, uint y, int level);
bool checkbit(unsigned int order, unsigned int index);

#endif
