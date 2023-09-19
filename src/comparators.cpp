#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "comparators.h"
#include "my_assert.h"
#include "strings.h"


int reverse_cmp(const void * p1, const void * p2)
{
    MY_ASSERT(p1 != nullptr);
    MY_ASSERT(p2 != nullptr);

    const char * const * string1 = (const char * const *) p1;
    const char * const * string2 = (const char * const *) p2;

    int string1_length = strlen(*string1) - 1;
    int string2_length = strlen(*string2) - 1;
    int i = string1_length;
    int j = string2_length;

    while (j >= 0 && i >= 0)
    {
        i = skip_nonalpha(*string1, i);
        j = skip_nonalpha(*string2, j);

        if ((*string1)[i] > (*string2)[j])
        {
            return 1;
        }
        else if ((*string1)[i] < (*string2)[j])
        {
            return -1;
        }
        else // string1[i] == strign2[j]
        {
            i--;
            j--;
        }
    }

    if (string1_length < string2_length)
        return -1;
    else if (string1_length > string2_length)
        return 1;
    else // string1_length == string2_length
        return 0;
}


int skip_nonalpha(const char * string, int index)
{
    while (!isalpha(string[index]))
        (index)--;

    return index;
}


int reverse_strcmp(const char * string1, const char * string2)
{
    MY_ASSERT(string1 != nullptr);
    MY_ASSERT(string2 != nullptr);

    int string1_length = strlen(string1) - 1;
    int string2_length = strlen(string2) - 1;
    int i = string1_length;
    int j = string2_length;

    while (j >= 0 && i >= 0)
    {
        i = skip_nonalpha(string1, i);
        j = skip_nonalpha(string2, j);

        if (string1[i] > string2[j])
        {
            return 1;
        }
        else if (string1[i] < string2[j])
        {
            return -1;
        }
        else // string1[i] == strign2[j]
        {
            i--;
            j--;
        }
    }

    if (string1_length < string2_length)
        return -1;
    else if (string1_length > string2_length)
        return 1;
    else // string1_length == string2_length
        return 0;
}


int normal_cmp(const void * p1, const void * p2)
{
    const char * const * string1 = (const char * const *) p1;
    const char * const * string2 = (const char * const *) p2;

    int i = 0;

    while ((*string1)[i] != '\0')
    {
        if      ((*string1)[i] > (*string2)[i])
        {
            return 1;
        }
        else if ((*string1)[i] < (*string2)[i])
        {
            return -1;
        }
        else
            i++;
    }

    if ((*string2)[i] == '\0')
        return 0;
    else
        return -1;
}
