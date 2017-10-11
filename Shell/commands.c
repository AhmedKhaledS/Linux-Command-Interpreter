#include <stdio.h>
#include "commands.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "variables.h"

const int MAX_VAR_LEN = 200;
const int MAX_MSG_LEN = 512;
void general_shell_command(char** argumentList)
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0)
    {
//        print("I am the child process");
//        char cwd[100];
//        getcwd(cwd, sizeof(cwd));
//        print(cwd);
        execvp(*argumentList, argumentList);
        perror("An error has occured while executing child process!");
    }
    else
    {
        if (commandProperties->foreground)
        {
            print("waiting for child\n");
            while (wait(&status) != pid);
        }
    }
    return;
}

void cd(const char* path)
{
    chdir(path);
}

void echo(const char* msg)
{

}

void assignment(const char* var, const char* value)
{
//    puts(var);
//    puts(value);
    set_variable(var, value);
    puts(look_up_variable(var));
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
        print("\n");
    }
}
void add_command(char* comm)
{
    history[command_counter++] = comm;
}

