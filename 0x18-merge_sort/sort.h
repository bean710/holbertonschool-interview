#ifndef _SORT_H_
#define _SORT_H_

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void top_down(int *array, int *temp, size_t start, size_t end);
void merge(int *array, int *temp, size_t start, size_t end, size_t middle);

#endif