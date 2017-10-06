#include <stdio.h>
#include <stdlib.h>
#include "ShellController.h"
#include <unistd.h>


const int MAX_LEN = 512;
const int MAX_COMMANDS = 1000;

/**
* This function pointer points to the mode-function of the command
* interpreter.
*/
void (*runner)();

void startShell(int argc, char* args[])
{
    unparsedCommand = (char*)malloc((size_t)MAX_LEN * sizeof(char));
    history = (char**)malloc((size_t)MAX_COMMANDS * sizeof(char*));
    load_history();
    if (!handle(argc, args))
    {
        puts("No such file or directory specified!\n");
        return;
    }
    (*runner)();
    save_history();
}

void runInteractiveMode()
{
    puts("Interactive mode is activated.\n");
    while (true)
    {
        printf("Shell> ");
        fflush(stdout);
        gets(unparsedCommand);
        char command_copy[MAX_LEN][MAX_LEN];
        strcpy(command_copy[command_counter], unparsedCommand);
        command_copy[command_counter][strlen(unparsedCommand)] = '\0';
        if (strlen(unparsedCommand) > MAX_LEN)
            error("Very long command, it exceeds 512 bytes!");
        parsedCommand = normalize(unparsedCommand);
        commandProperties = parse(parsedCommand);
        if (handle_exit())
            return;
        else if (!strcmp(parsedCommand[0], "history") && sizeOfWords == 1)
            print_history();
        else
        {
            partition_command();
    //        if (!strcmp(commandName, "echo"))
    //            echo(argList[1]);
    //        else if (!strcmp(commandName, "cd"))
    //            cd(argList);
    //        else
            general_shell_command(argList);
        }
        add_command(command_copy[command_counter]);
    }
}

void runBatchMode()
{
    puts("Batch mode is activated.\n");
    FILE* file;
    file = fopen(file_directory, "r");
    if (file == NULL)
    {
        error("No such file is found!");
        return;
    }
    char buffer[MAX_LEN];
    while (fgets(buffer, MAX_LEN, file) != NULL)
    {
        print(buffer);
    }
    fclose(file);
    return;
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


bool handle_exit()
{
    if (!strcmp(parsedCommand[0], "exit") && sizeOfWords == 1)
    {
        print("shell is terminated!");
        return true;
    }
    return false;
}

bool handle(int argc, char** args)
{
    if (argc == 2)
    {
        // Requires more handling.
        file_directory = args[1];
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
    perror(msg);
    // Here goes dealing with logger file.

}

void print(char* msg)
{
    printf("%s", msg);
    // Don't forget the logger.
}

void save_history()
{
    FILE* file;
    file = fopen("history.txt", "w");
    for (int line = 0; line < command_counter; line++)
    {
        fputs(history[line], file);
        fputc('\n', file);
    }
    fclose(file);
}

void load_history()
{
    FILE* file;
    if (access("history.txt", F_OK) != -1)
    {
        file = fopen("history.txt", "r");
        char buffer[MAX_COMMANDS][MAX_LEN];
        while (fgets(buffer[command_counter], MAX_LEN, file) != NULL)
        {
            //[command_counter][strlen(buffer[command_counter])] = '\0';
            add_command(buffer[command_counter]);
        }
        fclose(file);
    }
}
