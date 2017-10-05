#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variables.h"

void set_variable(const char* key, const char* value)
{
    for (int i = 0; i < lastIndex; i++)
    {
        if (!strcmp(key, table[i]))
        {
            table[i] = value;
            return;
        }
    }
    table[lastIndex++] = value;
    return;
}

const char* look_up_variable(const char* key)
{
    for (int i = 0; i < lastIndex; i++)
    {
        if (!strcmp(key, table[i]))
        {
            return table[i];
        }
    }
    error("This variable is not declared!");
    return "";
}

void print_all_variables()
{
    for (int i = 0; i < lastIndex; i++)
    {
        print(table[i]);
    }
}
