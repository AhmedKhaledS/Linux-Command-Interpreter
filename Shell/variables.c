#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variables.h"

void set_variable(const char* key, char* value)
{
    for (int i = 0; i < lastIndex; i++)
    {
        if (!strcmp(key, table[i].key))
        {
            table[i].value = value;
            return;
        }
    }
    table[lastIndex].key = key;
    table[lastIndex++].value = value;
    return;
}

const char* look_up_variable(const char* key)
{
    for (int i = 0; i < lastIndex; i++)
    {
        if (!strcmp(key, table[i].key))
        {
            return table[i].value;
        }
    }
    //error("This variable is not declared!");
    return "";
}

void print_all_variables()
{
    for (int i = 0; i < lastIndex; i++)
    {
        printf("%s = %s\n", table[i].key, table[i].value);
    }
}
