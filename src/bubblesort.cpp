#include <stdio.h>

#include "bubblesort.h"
#include "comparators.h"


void bubble_sort(char * * pointers, const size_t strings_num, int (*comparator)(const void *, const void *))
{
    char * tmp_pointer = NULL;

    for (size_t i = 0; i < strings_num; i++)
    {
        for (size_t j = i + 1; j < strings_num; j++)
        {
            int compare = comparator(&pointers[i], &pointers[j]);

            if (compare > 0)
            {
                tmp_pointer = pointers[i];
                pointers[i] = pointers[j];
                pointers[j] = tmp_pointer;
            }
        }
    }
}
