#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"
#include "tokenizer.h"

struct command_properties* parse(char** command)
{
    properties = malloc(sizeof(struct command_properties));

    return properties;
}

void handle_comment(char** command)
{
    if (command[0][0] == '#')
        properties->type = COMMENT;
}

void handle_foreground(char** command)
{
    if (command[sizeOfWords][strlen(command[sizeOfWords]) - 1] == '&')
        properties->foreground = false;
    else
        properties->foreground = true;
}
