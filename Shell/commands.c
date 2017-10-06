#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "commands.h"
#include "variables.h"


const int MAX_VAR_LEN = 200;
const int MAX_MSG_LEN = 200;
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
            print("waiting for child");
            while (wait(&status) != pid);
        }
    }
    return;
}

void cd(const char* path)
{

}
void echo(const char* msg)
{
//    //puts(msg);
//    char varChecker[MAX_VAR_LEN];
//    char message[MAX_MSG_LEN];
//    int counter = 0;
//    for (int i = 0; i < strlen(msg); i++)
//    {
//        if (msg[i] == "\"")
//            continue;
//        if (msg[i] == "$")
//        {
//            for (int j = i+1; j < strlen(msg) || msg[j] == "\""; j++)
//            {
//                varChecker[j-i-1] = msg[j];
//                i = j;
//            }
//            if (look_up_variable(varChecker) != "")
//            {
//                char* temp = look_up_variable(varChecker);
//                for (int j = 0; j < strlen(temp); j++)
//                    message[counter++] = temp[j];
//            }
//            continue;
//
//        }
//        message[counter++] = msg[i];
//    }
//    message[counter] = '\0';
//    print(message);
}
void assignment(const char* var, const char* value)
{

}
