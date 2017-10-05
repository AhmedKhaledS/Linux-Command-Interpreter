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
        printf("size: %d bytes\n", strlen(unparsedCommand));
        if (strlen(unparsedCommand) > MAX_LEN)
            error("Very long command, it exceeds 512 bytes!");
        parsedCommand = normalize(unparsedCommand);
        struct command_properties* comProperties = parse(parsedCommand);
    }
}

void runBatchMode()
{
    puts("Batch mode is activated.\n");
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
