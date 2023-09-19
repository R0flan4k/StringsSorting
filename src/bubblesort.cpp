#include <stdio.h>

#include "bubblesort.h"
#include "comparators.h"
#include "strings.h"

void bubble_sort(void * p, const size_t strings_num, const size_t size, int (*comparator)(const void *, const void *))
{
    char * * pointers = (char * *) p;

    for (size_t i = 0; i < strings_num; i++)
    {
        for (size_t j = i + 1; j < strings_num; j++)
        {
            int compare = comparator(&pointers[i], &pointers[j]);

            if (compare > 0)
            {
                switch_strings(&pointers[i], &pointers[j]);
            }
        }
    }
}
