#include <stdio.h>
#include <stdlib.h>

#include "strings.h"

int main(void)
{
    FILE * fp = NULL;

    if ((fp = file_open("EvgeniyOnegin.txt", "r")) == NULL)
        return 1;

    long file_size = get_file_size(fp);

    char * buffer = (char *) calloc(file_size + 1, sizeof(char));

    fread(buffer, file_size + 1, 1, fp);

    buffer[file_size] = '\0';

    puts("");

    size_t strings_num = get_strings_num(buffer, file_size + 1);

    char * * arrows = (char * *) calloc(strings_num, sizeof(char *));

    get_arrows(buffer, arrows, strings_num);

    sort_arrows(arrows, strings_num);

    for (size_t i = 0; i < strings_num; i++)
    {
        printf("%s\n", arrows[i]);
    }

    fclose (fp);
    free(buffer);
    free(arrows);

    return 0;
}