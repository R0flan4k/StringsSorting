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

    quick_sort1(strings, &strings[strings_num - 1]); // ??????????????????//
}


int quick_sort1(char * * left, char * * right)
{
    printf(RED_COLOR "%d\n" DEFAULT_COLOR, right - left);

    if (right - left <= 1)
    {
        return 0;
    }

    char * * abs_left  = left;
    char * * abs_right = right;
    char * * middle = partition(left, right);

    quick_sort1(abs_left, middle);
    quick_sort1(middle, abs_right);

    return 0;
}


char * * partition(char * * left, char * * right)
{
    srand((unsigned int) time(0));

    char * * abs_left  = left;
    char * * abs_right = right;
    char * * fundament = left + (rand() % (right - left - 1));

    char * fundament_string = *fundament;

    int left_cmp = 0, right_cmp = 0;

    show_pointers(abs_left, abs_right - abs_left, left, right);

    while (left < right)
    {
        while ((left_cmp = reverse_strcmp(*left, fundament_string)) > 0 && left < right)
        {
            left++;
        }

        while ((right_cmp = reverse_strcmp(*right, fundament_string)) <= 0 && left < right)
        {
            right--;
        }

        show_pointers(abs_left, abs_right - abs_left, left, right);

        if (left_cmp <= 0 && right_cmp > 0)
            switch_strings(left, right);
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


void show_pointers(char * * pointers, const size_t num, char * * left, char * * right)
{
    MY_ASSERT(pointers != nullptr && left != nullptr && right != nullptr);
    char * * tmp = pointers;

    puts("");

    while (tmp < left)
    {
        printf(CYAN_COLOR "%-3d" DEFAULT_COLOR, (tmp - pointers));
        tmp++;
    }

    printf(BLUE_COLOR "%-3d" DEFAULT_COLOR, (tmp - pointers));
    tmp++;

    while (tmp < right)
    {
        printf(GREEN_COLOR "%-3d" DEFAULT_COLOR, (tmp - pointers));
        tmp++;
    }

    printf(RED_COLOR "%-3d" DEFAULT_COLOR, (tmp - pointers));
    tmp++;

    while (tmp < pointers + num)
    {
        printf(MAGENTA_COLOR "%-3d" DEFAULT_COLOR, (tmp - pointers));
        tmp++;
    }

    printf("\n");

    puts("");
}
