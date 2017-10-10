#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "tokenizer.h"
#include "command_utils.h"
#include "file_service.h"
#ifndef SHELLCONTROLLER_H_INCLUDED
#define SHELLCONTROLLER_H_INCLUDED


char* unparsedCommand;
char** parsedCommand;
char* commandName;
char** argList;
char* file_directory;
char** history;
struct command_properties* commandProperties;
int command_counter;
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
* This function is responsible for handling empty command.
*/
bool handle_empty();

/**
* This function is responsible for handling exit command.
*/
bool handle_exit();

/**
* Handles the initialization of the shell to whether run in Batch
* ot Interactive mode. It also sends an error signal if there is
* an error occured while starting the shell.
*/
bool handle(int argc, char** args);




#endif // SHELLCONTROLLER_H_INCLUDED
