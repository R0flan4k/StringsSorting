#ifndef MYQSORT_H
    #define MYQSORT_H

    #define CYAN_COLOR "\x1b[36m"
    #define BLUE_COLOR "\x1b[34;1m"
    #define GREEN_COLOR "\x1b[32m"
    #define RED_COLOR "\x1b[31;1m"
    #define MAGENTA_COLOR "\x1b[35m"
    #define DEFAULT_COLOR "\x1b[0m"

    void quick_sort(void * p, const size_t strings_num, const size_t size, int (*comparator)(const void *, const void *));
    void quick_sort1(char * * strings, const size_t strings_num, int left, int right, int (*comparator)(const void *, const void *));
    int partition(char * * strings, const int strings_num, int left, int right, int (*comparator)(const void *, const void *));
    char * * get_bad_string_left(char * * left, const char * fundament, char * const * abs_right);
    char * * get_bad_string_right(char * * right, const char * fundament, char * const * abs_left);
    void show_pointers(char * * pointers, const int num, int left, int right);

#endif // MYQSORT_H
