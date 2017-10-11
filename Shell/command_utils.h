#ifndef COMMAND_UTILS_H_INCLUDED
#define COMMAND_UTILS_H_INCLUDED
#include <stdbool.h>
#include <string.h>

struct command_properties
{
    //char** arguments;
    char* type;
    bool foreground;
    char beforeEqual[256];
    char afterEqual[256];
};

char* copy_command(char* comm);

/**
* This function is resposible for printing status in both terminal
* and logger file.
*/
void print(char* msg);

/**
* Reports an error and prints it in standard std and logger file.
*/
void error(char* msg);


#endif // COMMAND_UTILS_H_INCLUDED
