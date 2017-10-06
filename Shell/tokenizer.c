#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

const int MAX_SIZE = 256;

char** normalize(char* line)
{
    sizeOfWords = 0;
    //free(normalizedCommand);
    normalizedCommand = (char**)malloc(sizeof(char*)*MAX_SIZE);
    char* tok = strtok(line, " ");
    while (tok != NULL)
    {
        normalizedCommand[sizeOfWords] = (char*)malloc(sizeof(char)*strlen(tok));
        normalizedCommand[sizeOfWords] = tok;
        sizeOfWords++;
        tok = strtok(NULL, " ");
    }
    normalizedCommand = (char**)realloc(normalizedCommand, sizeof(char*) * sizeOfWords);
    return normalizedCommand;
}
