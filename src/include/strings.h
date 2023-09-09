#ifndef STRINGS_H
    #define STRINGS_H

    long get_file_size(FILE * fp);
    FILE * file_open(const char * file_name, const char * mode);
    void show_text(const char * text5, const size_t size);
    size_t get_strings_num(char * buffer, const size_t size);
    void get_arrows(const char * buffer, char * arrows[], const size_t strings_num);
    void sort_arrows(char * * arrows, const size_t strings_num);
    int my_strcmp(const char * string1, const char * string2);
    int skip_nonalpha(const char * string, int * index);

#endif // STRINGS_H