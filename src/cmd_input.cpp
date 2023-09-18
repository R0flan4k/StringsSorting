#include <stdio.h>
#include <string.h>

#include "cmd_input.h"
#include "my_assert.h"
#include "myqsort.h"
#include "string.h"
#include "bubblesort.h"
#include "comparators.h"

CmdLineArg BUBBLE = {
    .name =         "--bubble",
    .num_of_param = 0,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--bubble"
};

CmdLineArg QSORT = {
    .name =         "--qsort",
    .num_of_param = 0,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--qsort"
};

CmdLineArg MYQSORT = {
    .name =         "--myqsort",
    .num_of_param = 0,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--myqsort"
};

CmdLineArg NORMAL = {
    .name =         "--normal",
    .num_of_param = 0,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--normal"
};

CmdLineArg REVERSE = {
    .name =         "--reverse",
    .num_of_param = 0,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--reverse"
};


bool check_cmd_input(int argc, char * * argv)
{
    MY_ASSERT(argv != nullptr);

    CmdLineArg * flags[SUPPORTED_FLAGS_NUMBER] = {&BUBBLE, &QSORT, &NORMAL, &REVERSE, &MYQSORT};

    for (int i = 0; i < SUPPORTED_FLAGS_NUMBER; i++)
    {
        for (int j = 1; j < argc; j++)
        {
            if (strcmp(flags[i]->name, argv[j]) == 0)
            {
                if (argc > j + flags[i]->num_of_param)
                {
                    flags[i]->argc_number = j;
                    flags[i]->necessity = true;
                }
                else
                {
                    printf("Error. Please, use %s %s\n", argv[0], flags[i]->help);
                    return false;
                }
            }
        }
    }

    if ((QSORT.necessity == false && BUBBLE.necessity == false && MYQSORT.necessity == false) || (NORMAL.necessity == false && REVERSE.necessity == false))
    {
        printf("Error. Please, use: %s --*sorter* --*comparator_mode*.\nAvailable sorters flags: --qsort, --bubble.\nAvailavle comparator mode flags: --normal, --reverse", argv[0]);

        return false;
    }

    return true;
}


void run_flag(char * * pointers, const size_t strings_num)
{
    if (BUBBLE.necessity)
    {
        run_bubble_sort(pointers, strings_num);
    }
    else if (QSORT.necessity)
    {
        run_qsort(pointers, strings_num);
    }
    else if (MYQSORT.necessity)
    {
        quick_sort(pointers, strings_num);
    }
    else
    {
        MY_ASSERT(0 && "NO FLAG");
    }
}


void run_bubble_sort(char * * pointers, const size_t strings_num)
{
    if (NORMAL.necessity)
    {
        bubble_sort(pointers, strings_num, normal_cmp);
    }
    else if (REVERSE.necessity)
    {
        bubble_sort(pointers, strings_num, reverse_cmp);
    }
    else
    {
        MY_ASSERT(0 && "NO FLAG");
    }
}


void run_qsort(char * * pointers, const size_t strings_num)
{
    if (NORMAL.necessity)
    {
        qsort(pointers, strings_num, sizeof(char * *), normal_cmp);
    }
    else if (REVERSE.necessity)
    {
        qsort(pointers, strings_num, sizeof(char * *), reverse_cmp);
    }
    else
    {
        MY_ASSERT(0 && "NO FLAG");
    }
}
