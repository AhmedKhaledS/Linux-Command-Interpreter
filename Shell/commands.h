#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED
#include "ShellController.h"



void general_shell_command(char** argumentList);
void cd(const char* path);
void echo(const char* msg);
void assignment(const char* var, const char* value);
void print_history();
void add_command(char* comm);

#endif // COMMANDS_H_INCLUDED
