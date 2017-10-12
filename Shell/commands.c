#include <stdio.h>
#include "commands.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "variables.h"
#include "sys/wait.h"

const int MAX_VAR_LEN = 256;
const int MAX_MSG_LEN = 512;
void general_shell_command(char** argumentList)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0)
    {
        log("Child process is launched.");
        execvp(*argumentList, argumentList);
        perror("An error has occured while executing child process!");
    }
    else
    {
        if (commandProperties->foreground)
        {
            print("waiting for child\n");
            do
            {
                waitpid(pid, &status, WUNTRACED);
            } while(!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    return;
}

void cd(const char* path)
{
    strcpy(current_directory, path);
    chdir(current_directory);
    getcwd(current_directory, sizeof(current_directory));
}

void echo(const char* msg)
{

}

void assignment(const char* var, const char* value)
{
    set_variable(var, value);
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

void print_history()
{
    for (int i = 0; i < command_counter; i++)
    {
        print(history[i]);
    }
}
void add_command(char* comm)
{
    history[command_counter++] = comm;
}

