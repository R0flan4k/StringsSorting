#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "strings.h"
#include "my_assert.h"
#include "comparators.h"


void show_text(const char * text5, const size_t size)
{
    size_t i = 0;

    while (i < size)
    {
        fputc(text5[i], stdout);

        i++;
    }
}


size_t get_strings_num(char * buffer)
{
    size_t strings_num = 0;
    char * string_pointer = buffer;

    while ((string_pointer = strchr(string_pointer, '\n')) != NULL)
    {
        *string_pointer = '\0';
        string_pointer++;
        strings_num++;
    }

    return strings_num + 1;
}


void get_pointers(const char * buffer, const char * pointers[], const size_t strings_num)
{
    size_t i = 0;
    char const * string_pointer = buffer;

    while (i < strings_num)
    {
        pointers[i] = string_pointer;

        string_pointer = strchr(string_pointer, '\0') + 1;

        i++;
    }
}


void switch_strings(char * * string1, char * * string2)
{
    char * tmp_string = *string1;

    *string1 = *string2;
    *string2 = tmp_string;
}


void show_strings(const char * const * strings, const size_t strings_num)
{
    for (size_t i = 0; i < strings_num; i++)
    {
        printf("%s\n", strings[i]);
    }
}


void sort_strings(const char * * pointers, const size_t strings_num, int (*comparator)(const void *, const void *), void (*sorter)(void *, size_t, size_t, int (*)(const void *, const void *)))
{
    sorter(pointers, strings_num, sizeof(char * *), comparator);
}
