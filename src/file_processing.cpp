#include <stdio.h>
#include <sys\stat.h>

#include "file_processing.h"
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
        printf("File error.");
    }

    return fp;
}


char * read_file(char * buffer, const size_t buffer_size, FILE * fp)
{
    int boo;
    if ((boo = fread(buffer, buffer_size, 1, fp)) != 0)
    {
        printf("Error. Can't read the file.\n");

        return NULL;
    }

    return buffer;
}
