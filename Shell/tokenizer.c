#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

const int MAX_SIZE = 513;

char** normalize(char* line)
{
    //char lineBuff[MAX_SIZE];
    //strcpy(lineBuff, line);
    //puts(line);
    sizeOfWords = 0;
    normalizedCommand = (char**)malloc(sizeof(char*)*MAX_SIZE);
    char* token = strtok(line, " ");
    while (token != NULL)
    {
        normalizedCommand[sizeOfWords] = (char*)malloc(sizeof(char)*MAX_SIZE);
        strcpy(normalizedCommand[sizeOfWords], token);
        normalizedCommand[sizeOfWords][strlen(token)] = '\0';
        sizeOfWords++;
        token = strtok(NULL, " ");
    }
    normalizedCommand = (char**)realloc(normalizedCommand, sizeof(char*) * sizeOfWords);
    return normalizedCommand;
}
