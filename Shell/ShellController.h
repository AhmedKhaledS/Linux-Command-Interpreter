#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tokenizer.h"
#ifndef SHELLCONTROLLER_H_INCLUDED
#define SHELLCONTROLLER_H_INCLUDED


char* unparsedCommand;
char** parsedCommand;
char* commandName;
char** argList;
char* currentDirectory;
struct command_properties* commandProperties;
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
* This function is responsible for splitting the parsed command into
* the name of the command and the argument list.
*/
void partition_command();
/**
* Reports an error and prints it in standard std and logger file.
*/
void error(char* msg);
/**
* Handles the initialization of the shell to whether run in Batch
* ot Interactive mode. It also sends an error signal if there is
* an error occured while starting the shell.
*/
bool handle(int argc);

/**
* This function is resposible for printing status in both terminal
* and logger file.
*/
void print(char* msg);


#endif // SHELLCONTROLLER_H_INCLUDED
