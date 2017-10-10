#include <stdbool.h>
#include <string.h>
#ifndef COMMAND_UTILS_H_INCLUDED
#define COMMAND_UTILS_H_INCLUDED

struct command_properties
{
    //char** arguments;
    char* type;
    bool foreground;
    char beforeEqual[200];
    char afterEqual[200];
};

char* copy_command(char* comm);

/**
* This function is resposible for printing status in both terminal
* and logger file.
*/
void print(char* msg);

#endif // COMMAND_UTILS_H_INCLUDED
