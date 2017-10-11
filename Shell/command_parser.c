#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"
#include "tokenizer.h"

const int MAX_LEN_VAR = 513;

void insert_substring(char *a, char *b, int position);
char* substring(char* string, int position, int length);


struct command_properties* parse(char** command)
{
    properties = malloc(sizeof(struct command_properties));
    handle_comment(command);
    handle_foreground(command);
    handle_command(command);
    handle_assignment(command);
    return properties;
}

void handle_comment(char** command)
{
    if (command[0][0] == '#')
    {
        properties->type = COMMENT;
    }
}

void handle_foreground(char** command)
{
    if (properties->type == COMMENT)
        return;
    if (command[sizeOfWords-1][strlen(command[sizeOfWords-1]) - 1] == '&')
        properties->foreground = false;
    else
        properties->foreground = true;

}

void handle_assignment(char** command)
{
    int equalIndex = -1;
    // If the upcoming expression does not start with '#'.
    if (properties->type != COMMENT)
    {
        for (int i = 0; i < strlen(command[0]); i++)
            if (command[0][i] == '=')
            {
                equalIndex = i;
                break;
            }
    }
    if (equalIndex == -1)
        return;
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
    // print("assignment\n");
//    printf("left operand: %s\n", properties->beforeEqual);
//    printf("after operand: %s\n", properties->afterEqual);
}

void handle_command(char** command)
{
    if (properties->type != COMMENT)
    {
        properties->type = COMMAND;
    }

    if (!strcmp(command[0], ECHO))
    {
        for (int i = 1; i < sizeOfWords; i++)
        {
            for (int j = 0; j < strlen(command[i]); j++)
            {
                char current[MAX_LEN_VAR];
                if (command[i][j] == '$')
                {
                    int k;
                    for (k = j+1; k < strlen(command[i]) && isalpha(command[i][k]); k++)
                    {
                        current[k-j-1] = command[i][k];
                    }
                    current[k-j-1] = '\0';
                    // puts(current);
                    // puts(look_up_variable(current));
                    if (strcmp(look_up_variable(current), ""))
                    {
                        char* value = look_up_variable(current);
                        for (int counter = 0; counter < strlen(current)+1; counter++)
                        {
                            memmove(&command[i][j], &command[i][j+1], strlen(command[i]) - j);
                        }
                        insert_substring(command[i], value, j+1);
                    }
                }
            }
        }
    }
    if (!strcmp(command[0], CD) || !strcmp(command[0], ECHO))
    {
        for (int i = 1; i < sizeOfWords; i++)
        {
            for (int j = 0; j < strlen(command[i]); j++)
            {
                if (command[i][j] == '~')
                {
                    if (strcmp(look_up_variable(HOME), ""))
                    {
                        char* value = look_up_variable(HOME);
                        memmove(&command[i][j], &command[i][j+1], strlen(command[i]) - j);
                        insert_substring(command[i], value, j+1);
                    }
                    else
                    {
                        memmove(&command[i][j], &command[i][j+1], strlen(command[i]) - j);
                        insert_substring(command[i], getenv(HOME), j+1);
                        printf("Home :  %s\n", command[i]);
                    }
                }
            }
        }
    }
}

void insert_substring(char *a, char *b, int position)
{
   char *f, *e;
   int length;

   length = strlen(a);

   f = substring(a, 1, position - 1);
   e = substring(a, position, length-position+1);

   strcpy(a, "");
   strcat(a, f);
   free(f);
   strcat(a, b);
   strcat(a, e);
   free(e);
}

char* substring(char* string, int position, int length)
{
   char* pointer;
   int c;

   pointer = malloc(length+1);

   if( pointer == NULL )
       exit(EXIT_FAILURE);

   for( c = 0 ; c < length ; c++ )
      *(pointer+c) = *((string+position-1)+c);

   *(pointer+c) = '\0';

   return pointer;
}
