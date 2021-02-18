#ifndef __MERGE_SORT__
#define __MERGE_SORT__

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void top_down(int *array, int *temp, size_t start, size_t end);
void merge(int *array, int *temp, size_t start, size_t end, size_t middle);

#endif