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
    getcwd(shell_directory, sizeof(shell_directory));
    chdir(getenv("HOME"));
    open_logging_file();
    getcwd(current_directory, sizeof(current_directory));
    load_history();
    if (!handle_mode(argc, args))
    {
        log("No such file or directory specified while opening batch-file!");
        puts("No such file or directory specified while opening batch-file!\n");
        return;
    }
    (*runner)();
    close_logging_file();
}

void runInteractiveMode()
{
    log("Interactive mode is activated.");
    puts("Interactive mode is activated.\n");
    while (true)
    {
        signal(SIGCHLD, log_child_process);
        fflush(stdout);
        printf(ANSI_COLOR_BLUE "Shell:" ANSI_COLOR_GREEN "%s>" ANSI_COLOR_RESET, current_directory);
        gets(unparsedCommand);

        char command_copy[MAX_LENGTH][MAX_LENGTH];
        strcpy(command_copy[command_counter], unparsedCommand);
        command_copy[command_counter][strlen(unparsedCommand)] = '\0';
        if (strlen(unparsedCommand) > MAX_LENGTH)
        {
            print("Very long command, it exceeds 512 bytes!");
            log("Very long command, it exceeds 512 bytes!");
            continue;
        }
        if(handle_empty())
            continue;
        parsedCommand = normalize(unparsedCommand);
        commandProperties = parse(parsedCommand);
        log("Command properties is extracted successfully.");
        log("Command is parsed successfully.");
        log("The command is starting execution...");
        if (commandProperties->type == "comment")
            continue;
        else if (handle_exit())
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
        log("Command is saved to the history file.");
    }
}

void runBatchMode()
{
    log("Batch mode is activated.\n");
    puts("Batch mode is activated.\n");
    FILE* file;
    char buffer[MAX_LENGTH];
    char* command_copy;
    //printf("%s\n", file_directory);
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
        strcpy(command_copy, unparsedCommand);
        if (strlen(unparsedCommand) > MAX_LENGTH)
        {
            print("Very long command, it exceeds 512 bytes!");
            log("Very long command, it exceeds 512 bytes!");
            continue;
        }
        //strcpy(sec_copy, unparsedCommand);
        if (handle_empty())
            continue;
        parsedCommand = normalize(copy_command(command_copy));
        commandProperties = parse(parsedCommand);
        log("Command properties is extracted successfully.");
        log("Command is parsed successfully.");
        log("The command is starting execution...");
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
                //printf("%s %s %s", argList[0], argList[1], argList[2]);
                general_shell_command(argList);
            }
        }
        add_command(copy_command(command_copy));
        free(command_copy);
        save_history();
        log("Command is saved to the history file.\n");
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
        len += strlen(parsedCommand[i]);
        if (i == 0)
            strcpy(tmp, parsedCommand[i]);
        else
            strcat(tmp, parsedCommand[i]);
        if (i != sizeOfWords-1)
            strcat(tmp, " "), len++;
    }
    tmp[len] = '\0';
    argList[COMMAND_INDEX] = (char*)malloc(sizeof(char)*strlen(tmp));
    strcpy(argList[COMMAND_INDEX], tmp);
    argList[COMMAND_NULL_TERMINATOR] = NULL;
}


bool handle_mode(int argc, char** args)
{
    if (argc == 2)
    {
        file_directory = args[1];
        runner = &runBatchMode;
    }
    else if (argc == 1)
        runner = &runInteractiveMode;
    else
        return false;
    return true;
}
