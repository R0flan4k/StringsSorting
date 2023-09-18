#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "strings.h"
#include "myqsort.h"
#include "my_assert.h"
#include "comparators.h"


void quick_sort(char * * strings, const size_t size)
{
    printf("%p and %p\n", strings, strings + size - 1);

    quick_sort1(strings, &strings[size - 1]); // ??????????????????//
}


int quick_sort1(char * * left, char * * right)
{
    if (right - left <= 1)
    {
        return 0;
    }


    char * * abs_left  = left;
    char * * abs_right = right;
    show_pointers(&abs_left, &abs_right - &abs_left, &left, &right);
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

    printf("%p\n%p\n", &left, &right);

    while (get_bad_string_left(&left, fundament_string, &abs_right) < get_bad_string_right(&right, fundament_string, &abs_left))
    {
        puts("");
        printf("%p\n%p\n", &left, &right);
        switch_strings(&left, &right);
    }

    return left;
}


char * * * get_bad_string_left(char * * * left, const char * fundament, char * const * const * abs_right)
{
    printf("in get_bad_string_left()\n");

    while (reverse_strcmp(*(*left), fundament) > 0 && left < abs_right)
    {
        left++;
        printf("get_bad_string_left() step\n");
    }

    return left;
}


char * * * get_bad_string_right(char * * * right, const char * fundament, char * const * const * abs_left)
{
    printf("In get_bad_string_right()\n");

    while (reverse_strcmp(*(*right), fundament) <= 0 && right > abs_left)
    {
        right--;
        printf("get_bad_string_right() step\n");
    }


    return right;
}


void show_pointers(char * * * pointers, const size_t num, char * * * left, char * * * right)
{
    MY_ASSERT(pointers != nullptr && left != nullptr && right != nullptr);
    char * * * tmp = pointers;

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
