#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED
#include "ShellController.h"



void general_shell_command(char** argumentList);
void cd(const char* path);
void echo(const char* msg);
void assignment(const char* var, const char* value);
void print_history();
void add_command(char* comm);

/**
* This function is responsible for handling empty command.
*/
bool handle_empty();

/**
* This function is responsible for handling exit command.
*/
bool handle_exit();

#endif // COMMANDS_H_INCLUDED
