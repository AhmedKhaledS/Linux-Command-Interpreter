#include <stdio.h>
#include <stdlib.h>
#include "ShellController.h"

const int MAX_LEN = 512;

void (*runner)();

void startShell(int argc, char* args[])
{
    if (!handle(argc))
    {
        puts("No such file or directory specified!\n");
        return;
    }
    unparsedCommand = (char*)malloc((size_t)MAX_LEN);
    (*runner)();

}

void runInteractiveMode()
{
    puts("Interactive mode is triggered.\n");
    while (true)
    {
        printf("Shell> ");
        fgets(unparsedCommand, MAX_LEN, stdin);

    }
}

void runBatchMode()
{
    puts("Batch mode is triggered.\n");
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
