#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"

struct command_properties* parse(char** command)
{
    properties = malloc(sizeof(struct command_properties));
    //struct command_properties test();
    if (command[0][0] == '#')
        properties->type = COMMENT;
    int lastInd = (int)sizeof(command) / ((int)sizeof (command[0]));
    printf("%d\n", lastInd);
    return properties;
}
