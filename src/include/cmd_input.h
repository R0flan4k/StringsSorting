#ifndef CMD_INPUT_H
    #define CMD_INPUT_H

    struct CmdLineArg {
        const char * name;                           ///< Name of flag.
        int num_of_param;                            ///< Number of flag parameters.
        void (*flag_function)(void);                 ///< Function of flag.
        int argc_number;                             ///< Serial number of flag in cmd line.
        const char * help;                           ///< How to use this flag.
    };

    extern CmdLineArg BUBBLE;
    extern CmdLineArg QSORT;
    extern CmdLineArg NORMAL;
    extern CmdLineArg REVERSE;
    extern CmdLineArg MYQSORT;
    extern CmdLineArg SOURCE;

    extern int (*COMPARATOR)(const void *, const void *);
    extern void (*SORTER)(void *, size_t, size_t, int (*)(const void *, const void *));
    extern const char * FILE_NAME;

    bool check_cmd_input(int argc, char * * argv);
    void set_flag_bubblesort(void);
    void set_flag_qsort(void);
    void set_flag_myqsort(void);
    void set_flag_normal(void);
    void set_flag_reverse(void);
    void set_flag_source(void);

#endif // CMD_INPUT_H
