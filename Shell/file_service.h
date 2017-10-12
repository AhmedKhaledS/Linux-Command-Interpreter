#ifndef FILE_SERVICE_H_INCLUDED
#define FILE_SERVICE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "ShellController.h"
#include <time.h>


/**
* This function saves history commands entered by the user in a file.
*/
void save_history();

/**
* This function loads the history commands entered by the user from a file.
*/
void load_history();

FILE* open_log_file(FILE *file);

void log_msg(FILE *file, char *msg, int pid);

void log_child_msg(FILE *file, char *msg, int pid);

void close_log_file(FILE *file);



#endif // FILE_SERVICE_H_INCLUDED
