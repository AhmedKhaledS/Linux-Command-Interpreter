#include <string.h>
#include "ShellController.h"
#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


char* table[100];
int lastIndex;

void set_variable(const char* key, char* value);
const char* look_up_variable(const char* key);
void print_all_variables();

#endif // VARIABLES_H_INCLUDED
