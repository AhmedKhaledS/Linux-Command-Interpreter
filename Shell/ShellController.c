#include "ShellController.h"

const int MAX_LENGTH = 512;
const int MAX_COMMANDS_LEN = 1000;

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
        if (commandProperties->type == "comment")
            continue;
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
        add_command(copy_command(command_copy));
    }
    fclose(file);
    return;
}


void partition_command()
{
    commandName = (char*)malloc(sizeof(char)*(MAX_LENGTH/2));
    strcpy(commandName, "./bin/bash");
    argList = (char**)malloc(sizeof(char*)*(4));
    argList[0] ="/bin/bash";
    argList[1] = "-c";
    int len = 0;
    char tmp[MAX_LENGTH];
    for (int i = 0; i < sizeOfWords; i++)
    {
        puts(parsedCommand[i]);
        len += strlen(parsedCommand[i]);
        if (i == 0)
            strcpy(tmp, parsedCommand[i]);
        else
            strcat(tmp, parsedCommand[i]);
        if (i != sizeOfWords-1)
            strcat(tmp, " "), len++;
    }
    tmp[len] = '\0';
    print(tmp);
    argList[2] = tmp;
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

bool handle_empty()
{
    return !strcmp("", unparsedCommand);
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




