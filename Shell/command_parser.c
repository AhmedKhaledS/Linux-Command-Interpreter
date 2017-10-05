#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"

const int MAX_SIZE = 256;

char** parse(char* line)
{
    int sizeOfWords = 0;
    parsed = (char**)malloc(sizeof(char*)*MAX_SIZE);
    char* tok = strtok(line, " ");
    while (tok != NULL)
    {
        parsed[sizeOfWords] = (char*)malloc(sizeof(char)*strlen(tok));
        parsed[sizeOfWords] = tok;
        sizeOfWords++;
        tok = strtok(NULL, " ");
    }
    parsed = (char**)realloc(parsed, sizeof(char*) * sizeOfWords);
    return parsed;
}
