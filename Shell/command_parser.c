#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"
#include "tokenizer.h"

struct command_properties* parse(char** command)
{
    properties = malloc(sizeof(struct command_properties));
    handle_comment(command);
    handle_foreground(command);
    handle_assignment(command);
    handle_command(command);
    return properties;
}

void handle_comment(char** command)
{
    if (command[0][0] == '#')
    {
        properties->type = COMMENT;
        print("comment\n");
    }
}

void handle_foreground(char** command)
{
    if (properties->type == COMMENT)
        return;
    if (command[sizeOfWords-1][strlen(command[sizeOfWords-1]) - 1] == '&')
        properties->foreground = false, print("background");
    else
        properties->foreground = true;

}

void handle_assignment(char** command)
{
    int countEquals = 0, equalIndex = -1;
    // If the upcoming expression does not start with '#'.
    if (properties->type != COMMENT)
    {
        for (int i = 0; i < strlen(command[0]); i++)
            if (command[0][i] == '=')
                countEquals++, equalIndex = i;
    }
    if (countEquals == 1)
    {
        properties->type = ASSIGNMENT;
        // Dynamically allocate the size of string before and after assignment.
        //properties->beforeEqual = (char*)malloc(sizeof(char)*(equalIndex+10));
        //properties->afterEqual = (char*)malloc(sizeof(char)*(strlen(command[0])-equalIndex+10));
        for (int i = 0; i < equalIndex; i++)
            properties->beforeEqual[i] = command[0][i];
        properties->beforeEqual[equalIndex] = '\0';
        for (int i = equalIndex+1; i < strlen(command[0]); i++)
            properties->afterEqual[i-equalIndex-1] = command[0][i];
        properties->afterEqual[strlen(command[0])-equalIndex-1] = '\0';
        print("assignment\n");
        printf("left operand: %s\n", properties->beforeEqual);
        printf("after operand: %s\n", properties->afterEqual);
    }
}

void handle_command(char** command)
{
    if (properties->type != COMMENT && properties->type != ASSIGNMENT)
    {
        properties->type = COMMAND;
        print("command\n");
    }
}
