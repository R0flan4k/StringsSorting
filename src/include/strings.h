#ifndef STRINGS_H
    #define STRINGS_H

    void show_text(const char * text5, const size_t size);
    size_t get_strings_num(char * buffer);
    void get_pointers(const char * buffer, const char * pointers[], const size_t strings_num);
    void switch_strings(char * * string1, char * * string2);
    void sort_strings(const char * * pointers, const size_t strings_num, int (*comparator)(const void *, const void *), void (*sorter)(void *, size_t, size_t, int (*)(const void *, const void *)));
    void show_strings(const char * const * strings, const size_t strings_num);

#endif // STRINGS_H
