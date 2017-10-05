#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef SHELLCONTROLLER_H_INCLUDED
#define SHELLCONTROLLER_H_INCLUDED


char* unparsedCommand;
/**
* This function starts running the shell program until the end
* of commands or until a fatal error occurs.
*/
void startShell(int argc, char* args[]);
/**
* This function starts running the shell program in the Interactive
* mode.
*/
void runInteractiveMode();
/**
* This function starts running the shell program in the Batch
* mode.
*/
void runBatchMode();
/**
* Handles the initialization of the shell to whether run in Batch
* ot Interactive mode. It also sends an error signal if there is
* an error occured while starting the shell.
*/
bool handle(int argc);

#endif // SHELLCONTROLLER_H_INCLUDED
