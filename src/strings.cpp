#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys\stat.h>
#include <ctype.h>

#include "strings.h"
#include "my_assert.h"


long get_file_size(FILE * fp)
{
    struct stat buffer = {};

    fstat(fileno(fp), &buffer);

    return buffer.st_size;
}


FILE * file_open(const char * file_name, const char * mode)
{
    FILE * fp = NULL;

    if ((fp = fopen(file_name, mode)) == NULL)
    {                                                    
        printf("File error");
    }

    return fp;
}


void show_text(const char * text5, const size_t size)
{
    size_t i = 0;

    while (i < size)
    {
        fputc(text5[i], stdout);

        i++;
    }
}


size_t get_strings_num(char * buffer, const size_t size)
{
    size_t i = 0;
    size_t strings_num = 0;

    while (i < size)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';

            strings_num++;
        }

        i++;
    }

    return strings_num;
}


void get_arrows(const char * buffer, char * arrows[], const size_t strings_num)
{
    size_t i = 1;
    size_t j = 0;

    arrows[0] = const_cast <char *> (buffer);

    while (i < strings_num)
    {
        while (buffer[j] != '\0')
            j++;
        
        j++;

        arrows[i] = const_cast <char *> (&buffer[j]);

        i++;
    }
}


void sort_arrows(char * * arrows, const size_t strings_num)
{
    char * intermediate_pointer = NULL;

    for (size_t i = 0; i < strings_num; i++)
        for (size_t j = i + 1; j < strings_num; j++)
        {
            int compare = my_strcmp(arrows[i], arrows[j]);

            if (compare > 0)
            {
                intermediate_pointer = arrows[i];
                arrows[i] = arrows[j];
                arrows[j] = intermediate_pointer;
            } 
        }
}


int my_strcmp(const char * string1, const char * string2)
{
    MY_ASSERT(string1 != nullptr && string2 != nullptr);

    int string1_length = strlen(string1) - 1;
    int string2_length = strlen(string2) - 1;
    int i = string1_length;
    int j = string2_length;

    while (j >= 0 && i >= 0)
    {
        skip_nonalpha(string1, &i);
        skip_nonalpha(string2, &j);

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


int skip_nonalpha(const char * string, int * index)
{
    while (!isalpha(string[*index]))
        (*index)--;

    return *index;
}