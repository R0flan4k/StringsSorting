#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd_input.h"
#include "my_assert.h"
#include "myqsort.h"
#include "string.h"
#include "bubblesort.h"
#include "comparators.h"

int (*COMPARATOR)(const void *, const void *) = NULL;
void (*SORTER)(void *, size_t, size_t, int (*)(const void *, const void *)) = NULL;
const char * FILE_NAME = NULL;
static char * * cmd_input = NULL;

CmdLineArg BUBBLE = {
    .name =          "--bubble",
    .num_of_param =  0,
    .flag_function = set_flag_bubblesort,
    .argc_number =   0,
    .help =          "--bubble"
};

CmdLineArg QSORT = {
    .name =          "--qsort",
    .num_of_param =  0,
    .flag_function = set_flag_qsort,
    .argc_number =   0,
    .help =          "--qsort"
};

CmdLineArg MYQSORT = {
    .name =          "--myqsort",
    .num_of_param =  0,
    .flag_function = set_flag_myqsort,
    .argc_number =   0,
    .help =          "--myqsort"
};

CmdLineArg NORMAL = {
    .name =          "--normal",
    .num_of_param =  0,
    .flag_function = set_flag_normal,
    .argc_number =   0,
    .help =          "--normal"
};

CmdLineArg REVERSE = {
    .name =          "--reverse",
    .num_of_param =  0,
    .flag_function = set_flag_reverse,
    .argc_number =   0,
    .help =          "--reverse"
};

CmdLineArg SOURCE = {
    .name =          "--source",
    .num_of_param =  1,
    .flag_function = set_flag_source,
    .argc_number =   0,
    .help =          "--source *file name*"
};



bool check_cmd_input(int argc, char * * argv)
{
    MY_ASSERT(argv != nullptr);

    cmd_input = argv;

    const char * program_name = argv[0];

    CmdLineArg * flags[] = {&BUBBLE, &QSORT, &NORMAL, &REVERSE, &MYQSORT, &SOURCE};
    size_t flags_array_size = sizeof(flags) / sizeof(flags[0]);

    for (size_t i = 0; i  < flags_array_size; i++)
    {
        for (int j = 1; j < argc; j++)
        {
            if (strcmp(flags[i]->name, argv[j]) == 0)
            {
                if (argc > j + flags[i]->num_of_param)
                {
                    flags[i]->argc_number = j;

                    flags[i]->flag_function();
                }
                else
                {
                    printf("Error. Please, use %s %s\n", program_name, flags[i]->help);
                    return false;
                }
            }
        }
    }

    if (SORTER == NULL || COMPARATOR == NULL || FILE_NAME == NULL)
    {
        printf("Error. Please, use: %s --*sorter* --*comparator mode* --source *file name*.\n"
               "Available sorters flags: --qsort, --bubble.\n"
               "Availavle comparator mode flags: --normal, --reverse\n", program_name);

        return false;
    }

    return true;
}


void set_flag_bubblesort(void)
{
    SORTER = bubble_sort;
}


void set_flag_qsort(void)
{
    SORTER = qsort;
}


void set_flag_myqsort(void)
{
    SORTER = quick_sort;
}


void set_flag_normal(void)
{
    COMPARATOR = normal_cmp;
}


void set_flag_reverse(void)
{
    COMPARATOR = reverse_cmp;
}


void set_flag_source(void)
{
    FILE_NAME = cmd_input[SOURCE.argc_number + 1];
}
