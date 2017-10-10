#ifndef FILE_SERVICE_H_INCLUDED
#define FILE_SERVICE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "ShellController.h"

/**
* This function saves history commands entered by the user in a file.
*/
void save_history();

/**
* This function loads the history commands entered by the user from a file.
*/
void load_history();

#endif // FILE_SERVICE_H_INCLUDED
