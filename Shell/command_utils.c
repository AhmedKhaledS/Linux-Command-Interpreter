#include "command_utils.h"
#include "stdbool.h"


char* copy_command(char* comm)
{
    char* copyy = (char*)malloc(sizeof(char)*(strlen(comm)));
    for (int i = 0; i < strlen(comm); i++)
        copyy[i] = comm[i];
    copyy[strlen(comm)] = '\0';
    return copyy;
}

void print(char* msg)
{
    printf("%s", msg);
    // Don't forget the logger.
}

void error(char* msg)
{
    perror(msg);
    // Here goes dealing with logger file.

}
