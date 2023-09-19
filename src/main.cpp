#include <stdio.h>
#include <stdlib.h>

#include "strings.h"
#include "file_processing.h"
#include "cmd_input.h"
#include "my_assert.h"

int main(int argc, char * argv[])
{
    if (check_cmd_input(argc, argv) == false)
        return 1;

    FILE * fp = NULL;

    if ((fp = file_open(FILE_NAME, "r")) == NULL)
        return 1;

    long file_size = get_file_size(fp);
    long buffer_size = file_size + 1;

    char * buffer = NULL;
    if ((buffer = (char *) calloc(file_size + 1, sizeof(char))) == NULL)
    {
        printf("Can't allocate memory.");
        fclose(fp);

        return 1;
    }

    if ((buffer = read_file(buffer, buffer_size, fp)) == NULL)
    {
        fclose(fp);
        free(buffer);

        return 1;
    }

    buffer[buffer_size - 1] = '\0';

    size_t strings_num = get_strings_num(buffer);

    const char * * pointers = NULL;
    if ((pointers = (const char * *) calloc(strings_num, sizeof(char *))) == NULL)
    {
        printf("Can't allocate memory.");
        fclose(fp);
        free(buffer);

        return 1;
    }

    get_pointers(buffer, pointers, strings_num);

    sort_strings(pointers, strings_num, COMPARATOR, SORTER);

    show_strings(pointers, strings_num);

    fclose(fp);
    free(buffer);
    free(pointers);

    getchar();

    return 0;
}
