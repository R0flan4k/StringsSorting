#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "strings.h"
#include "myqsort.h"
#include "my_assert.h"
#include "comparators.h"


void quick_sort(void * p, const size_t strings_num, const size_t size, int (*comparator)(const void *, const void *))
{
    char * * strings = (char * *) p;

    quick_sort1(strings, strings_num, 0, strings_num - 1); // ??????????????????//
}


void quick_sort1(char * * strings, const size_t strings_num, int left, int right)
{
    printf(RED_COLOR "%d\n" DEFAULT_COLOR, right - left);

    if (right - left > 1)
    {
        int abs_left =  left;
        int abs_right = right;
        int middle = partition(strings, strings_num, left, right);
        int lmiddle = middle - 1;
        int rmiddle = middle + 1;

        MY_ASSERT(lmiddle >= 0);
        MY_ASSERT(rmiddle <= strings_num - 1);

        quick_sort1(strings, strings_num, abs_left, lmiddle);
        quick_sort1(strings, strings_num, rmiddle, abs_right);
    }
}


int partition(char * * strings, const size_t strings_num, int left, int right)
{
    srand((unsigned int) time(0));

    int abs_left  = left;
    int abs_right = right;
    int randomchik = rand() % (right - left - 1);
    int fundament = left + (randomchik);

    puts("");
    printf("%d\n", randomchik);
    puts("");

    char * fundament_string = strings[fundament];

    int left_cmp = 0, right_cmp = 0;

    show_pointers(strings, strings_num, left, right);

    while (left < right)
    {
        while ((left_cmp = reverse_strcmp(strings[left], fundament_string)) < 0 && left < right)
        {
            left++;
        }

        while ((right_cmp = reverse_strcmp(strings[right], fundament_string)) >= 0 && left < right)
        {
            right--;
        }

        show_pointers(strings, strings_num, left, right);

        if (left_cmp >= 0 && right_cmp < 0)
            switch_strings(&strings[left], &strings[right]);
    }

    return left;
}


char * * get_bad_string_left(char * * left, const char * fundament, char * const * abs_right)
{
    printf("in get_bad_string_left()\n");

    while (reverse_strcmp(*left, fundament) > 0 && left < abs_right)
    {
        left++;
        printf("get_bad_string_left() step\n");
    }

    return left;
}


char * * get_bad_string_right(char * * right, const char * fundament, char * const * abs_left)
{
    printf("In get_bad_string_right()\n");

    while (reverse_strcmp(*right, fundament) <= 0 && right > abs_left)
    {
        right--;
        printf("get_bad_string_right() step\n");
    }


    return right;
}


void show_pointers(char * * pointers, const size_t num, int left, int right)
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
