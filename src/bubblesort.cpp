#include <stdio.h>

#include "bubblesort.h"
#include "comparators.h"
#include "strings.h"


void bubble_sort(void * p, const size_t strings_num, const size_t size, int (*comparator)(const void *, const void *))
{
    char tmp = 0;

    for (size_t i = 0; i < strings_num; i++)
    {
        for (size_t j = i + 1; j < strings_num; j++)
        {
            int compare = comparator(((char *) p + size * i), ((char *) p + size * j));

            if (compare > 0)
            {
                for (size_t k = 0; k < size; k++)
                {
                    tmp = *((char *) p + size * i + k);
                    *((char *) p + size * i + k) = *((char *) p + size * j + k);
                    *((char *) p + size * i + k) = tmp;
                }
            }
        }
    }
}
