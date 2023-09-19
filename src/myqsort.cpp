#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "strings.h"
#include "myqsort.h"
#include "my_assert.h"
#include "comparators.h"
#include "cmd_input.h"


void quick_sort(void * p, const size_t strings_num, const size_t size, int (*comparator)(const void *, const void *))
{
    char * * strings = (char * *) p;

    quick_sort1(strings, strings_num, 0, strings_num - 1, comparator);
}


void quick_sort1(char * * strings, const size_t strings_num, int left, int right, int (*comparator)(const void *, const void *))
{
    // printf(RED_COLOR "%d\n" DEFAULT_COLOR, right - left);

    if (right > left + 1)
    {
        int middle = partition(strings, strings_num, left, right, comparator);
        int lmiddle = middle - 1;
        int rmiddle = middle + 1;

        // if (middle == 0)
        // {
        //     lmiddle = middle;
        //     rmiddle = middle + 1;
        // }
        // else
        // {
        //     lmiddle = middle - 1;
        //     rmiddle = middle;
        // }

        // MY_ASSERT(lmiddle >= 0);
        // MY_ASSERT(rmiddle <= strings_num - 1);

        quick_sort1(strings, strings_num, left, lmiddle, comparator);
        quick_sort1(strings, strings_num, rmiddle, right, comparator);
    }
    else if (right == left + 1 && (comparator(&strings[left], &strings[right])) > 0)
    {
        switch_strings(&strings[left], &strings[right]);
    }
}


int partition(char * * strings, const int strings_num, int left, int right, int (*comparator)(const void *, const void *))
{
    srand((unsigned int) time(0));

    int randomchik = rand() % (right - left - 1);
    int fundament = left + (randomchik);

    MY_ASSERT(0 <= left && left <= strings_num - 1);
    MY_ASSERT(0 <= right && right <= strings_num - 1);

    // puts("");
    // printf("%d\n", randomchik);
    // puts("");

    char * fundament_string = strings[fundament];

    int left_cmp = 0, right_cmp = 0;

    // show_pointers(strings, strings_num, left, right);

    while (left < right)
    {
        while ((left_cmp = comparator(&strings[left], &fundament_string)) < 0 && left < right)
        {
            left++;
        }

        while ((right_cmp = comparator(&strings[right], &fundament_string)) >= 0 && left < right)
        {
            right--;
        }

        // show_pointers(strings, strings_num, left, right);

        if (left_cmp >= 0 && right_cmp < 0)
            switch_strings(&strings[left], &strings[right]);
    }

    return left;
}


// char * * get_bad_string_left(char * * left, const char * fundament, char * const * abs_right)
// {
//     printf("in get_bad_string_left()\n");
//
//     while (reverse_strcmp(*left, fundament) > 0 && left < abs_right)
//     {
//         left++;
//         printf("get_bad_string_left() step\n");
//     }
//
//     return left;
// }
//
//
// char * * get_bad_string_right(char * * right, const char * fundament, char * const * abs_left)
// {
//     printf("In get_bad_string_right()\n");
//
//     while (reverse_strcmp(*right, fundament) <= 0 && right > abs_left)
//     {
//         right--;
//         printf("get_bad_string_right() step\n");
//     }
//
//
//     return right;
// }


void show_pointers(char * * pointers, const int num, int left, int right)
{
    MY_ASSERT(pointers != nullptr);

    int tmp = 0;

    puts("");

    while (tmp < left)
    {
        printf(CYAN_COLOR "%-5d" DEFAULT_COLOR, (tmp));
        tmp++;
    }

    printf(BLUE_COLOR "%-5d" DEFAULT_COLOR, (tmp));
    tmp++;

    while (tmp < right)
    {
        printf(GREEN_COLOR "%-5d" DEFAULT_COLOR, (tmp));
        tmp++;
    }

    printf(RED_COLOR "%-5d" DEFAULT_COLOR, (tmp));
    tmp++;

    while (tmp < num)
    {
        printf(MAGENTA_COLOR "%-5d" DEFAULT_COLOR, (tmp));
        tmp++;
    }

    printf("\n");

    puts("");
}

