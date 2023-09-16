#ifndef MYQSORT_H
    #define MYQSORT_H

    void quick_sort(char * * strings, const size_t size);
    int quick_sort1(char * * left, char * * right);
    char * * partition(char * * left, char * * right);
    char * * * get_bad_string_left(char * * * left, const char * fundament, char * const * const * abs_right);
    char * * * get_bad_string_right(char * * * right, const char * fundament, char * const * const * abs_left);

#endif // MYQSORT_H