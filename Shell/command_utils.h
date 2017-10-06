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

#endif // COMMAND_UTILS_H_INCLUDED
