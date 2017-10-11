#include "ShellController.h"

const int MAX_LENGTH = 512;
const int MAX_COMMANDS_LEN = 1000;
const int COMMAND_WORDS_SIZE = 4;
const int GENERAL_COMMAND_ID = 0;
const int GENERAL_COMMAND_OPTION_ID = 1;
const int COMMAND_INDEX = 2;
const int COMMAND_NULL_TERMINATOR = 3;


/**
* This function pointer points to the mode-function of the command
* interpreter.
*/
void (*runner)();

void startShell(int argc, char* args[])
{
    unparsedCommand = (char*)malloc((size_t)MAX_LENGTH * sizeof(char));
    history = (char**)malloc((size_t)MAX_COMMANDS_LEN * sizeof(char*));
    load_history();
    if (!handle_mode(argc, args))
    {
        puts("No such file or directory specified!\n");
        return;
    }
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
        char command_copy[MAX_LENGTH][MAX_LENGTH];
        strcpy(command_copy[command_counter], unparsedCommand);
        command_copy[command_counter][strlen(unparsedCommand)] = '\0';
        if (strlen(unparsedCommand) > MAX_LENGTH)
            error("Very long command, it exceeds 512 bytes!");
        parsedCommand = normalize(unparsedCommand);
        commandProperties = parse(parsedCommand);
        if (handle_exit())
            return;
        else if (!strcmp(parsedCommand[0], "history") && sizeOfWords == 1)
            print_history();
        else if (!strcmp(parsedCommand[0], "cd") && sizeOfWords == 2)
        {
            cd(parsedCommand[1]);
        }
        else
        {
            if (!strcmp(commandProperties->type, "assignment") && sizeOfWords == 1)
            {
                assignment(commandProperties->beforeEqual, commandProperties->afterEqual);
            }
            else
            {
                partition_command();
                general_shell_command(argList);

            }
        }
        add_command(command_copy[command_counter]);
        save_history();
    }
}

void runBatchMode()
{
    puts("Batch mode is activated.\n");
    FILE* file;
    char buffer[MAX_LENGTH];
    char* command_copy;
    file = fopen(file_directory, "r");
    if (file == NULL)
    {
        error("No such file is found!");
        return;
    }
    while (fgets(buffer, MAX_COMMANDS_LEN, file) != NULL)
    {
        print(buffer);
        unparsedCommand = buffer;
        unparsedCommand[strlen(unparsedCommand)-1] = '\0';
        command_copy = (char*)malloc(sizeof(char)*strlen(unparsedCommand));
        //command_copy = copy_command(unparsedCommand);
        strcpy(command_copy, unparsedCommand);
        //strcpy(sec_copy, command_copy);
        if (strlen(unparsedCommand) > MAX_LENGTH)
            error("Very long command, it exceeds 512 bytes!");
        //strcpy(sec_copy, unparsedCommand);
        if (handle_empty())
            continue;
        parsedCommand = normalize(copy_command(command_copy));
        commandProperties = parse(parsedCommand);
        free(command_copy);
        if (commandProperties->type == "comment")
            continue;
        if (handle_exit())
            return;
        else if (!strcmp(parsedCommand[0], "history") && sizeOfWords == 1)
            print_history();
        else
        {
            if (!strcmp(commandProperties->type, "assignment") && sizeOfWords == 1)
            {
                assignment(commandProperties->beforeEqual, commandProperties->afterEqual);
            }
            else
            {
                partition_command();
                general_shell_command(argList);

            }
        }
        add_command(copy_command(command_copy));
        save_history();
    }
    fclose(file);
    return;
}


void partition_command()
{
    /// Here we have to handle home directory with cd.
    argList = (char**)malloc(sizeof(char*)*(COMMAND_WORDS_SIZE));
    argList[GENERAL_COMMAND_ID] ="/bin/bash";
    argList[GENERAL_COMMAND_OPTION_ID] = "-c";
    int len = 0;
    char tmp[MAX_LENGTH];
    for (int i = 0; i < sizeOfWords; i++)
    {
        //puts(parsedCommand[i]);
        len += strlen(parsedCommand[i]);
        if (i == 0)
            strcpy(tmp, parsedCommand[i]);
        else
            strcat(tmp, parsedCommand[i]);
        if (i != sizeOfWords-1)
            strcat(tmp, " "), len++;
    }
    tmp[len] = '\0';
    //print(tmp);
    argList[COMMAND_INDEX] = tmp;
    argList[COMMAND_NULL_TERMINATOR] = NULL;
}


bool handle_mode(int argc, char** args)
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
