#ifndef CMD_INPUT_H
    #define CMD_INPUT_H

    struct CmdLineArg {
        const char * name; ///< Name of flag.
        int num_of_param;  ///< Number of flag parameters.
        bool necessity;    ///< Necessity of flag.
        int argc_number;   ///< Serial number of flag in cmd line.
        const char * help; ///< How to use this flag.
    };

    const int SUPPORTED_FLAGS_NUMBER = 5; ///< Number of supported flags.

    extern CmdLineArg BUBBLE;
    extern CmdLineArg QSORT;
    extern CmdLineArg NORMAL;
    extern CmdLineArg REVERSE;
    extern CmdLineArg MYQSORT;

    bool check_cmd_input(int argc, char * * argv);
    void run_flag(char * * pointers, const size_t strings_num);
    void run_bubble_sort(char * * pointers, const size_t strings_num);
    void run_qsort(char * * pointers, const size_t strings_num);

#endif // CMD_INPUT_H
