#ifndef COMPARATORS_H
    #define COMPARATORS_H

    int reverse_cmp(const void * p1, const void * p2);
    int reverse_strcmp(const char * string1, const char * string2);
    int skip_nonalpha(const char * string, int index);
    int normal_cmp(const void * p1, const void * p2);

#endif // COMPARATORS_H