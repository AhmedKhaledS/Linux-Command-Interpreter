#include <stdio.h>
#include <stdlib.h>
#include "ShellController.h"


const int MAX_LEN = 512;

/**
* This function pointer points to the mode-function of the command
* interpreter.
*/
void (*runner)();

void startShell(int argc, char* args[])
{
    if (!handle(argc))
    {
        puts("No such file or directory specified!\n");
        return;
    }
    unparsedCommand = (char*)malloc((size_t)MAX_LEN * sizeof(char));
    (*runner)();

}

void runInteractiveMode()
{
    puts("Interactive mode is activated.\n");
    while (true)
    {
        fflush(stdout);
        printf("Shell> ");
        gets(unparsedCommand);
//        printf("size: %d bytes\n", strlen(unparsedCommand));
        if (strlen(unparsedCommand) > MAX_LEN)
            error("Very long command, it exceeds 512 bytes!");
        parsedCommand = normalize(unparsedCommand);
        commandProperties = parse(parsedCommand);
        partition_command();
//        if (!strcmp(commandName, "echo"))
//            echo(argList[1]);
//        else if (!strcmp(commandName, "cd"))
//            cd(argList);
//        else
            general_shell_command(argList);
    }
}

void runBatchMode()
{
    puts("Batch mode is activated.\n");
}

void partition_command()
{
    commandName = (char*)malloc(sizeof(char)*(MAX_LEN/2));
    strcpy(commandName, "./bin/bash");
    argList = (char**)malloc(sizeof(char*)*(4));
    argList[0] ="/bin/bash";
    argList[1] = "-c";
    int len = 0;
    char tmp[MAX_LEN];
    for (int i = 0; i < sizeOfWords; i++)
    {
        len += strlen(parsedCommand[i]);
        if (i == 0)
            strcpy(tmp, parsedCommand[i]);
        else
            strcat(tmp, parsedCommand[i]);
        if (i != sizeOfWords-1)
            strcat(tmp, " "), len++;
    }
    tmp[len] = '\0';
//    print(tmp);
    argList[2] = tmp;
//    print(argList[0]);
//    print(argList[1]);
//    print(argList[2]);
    argList[3] = NULL;
}
bool handle(int argc)
{
    if (argc == 2)
    {
        // Requires more handling.
        runner = &runBatchMode;
    }
    else if (argc == 1)
        runner = &runInteractiveMode;
    else
        return false;
    return true;
}

void error(char* msg)
{
    puts(msg);
    // Here goes dealing with logger file.

}

void print(char* msg)
{
    puts(msg);
    // Don't forget the logger.
}
