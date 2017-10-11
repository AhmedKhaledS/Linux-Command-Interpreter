#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"
#include "tokenizer.h"
#include "command_utils.h"
#include "file_service.h"
#include "environment.h"
#include "logger.h"
#ifndef SHELLCONTROLLER_H_INCLUDED
#define SHELLCONTROLLER_H_INCLUDED
#define  MAX_PATH_LEN  1024
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

char* unparsedCommand;
char current_directory[MAX_PATH_LEN];
char shell_directory[MAX_PATH_LEN];
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
* Handles the initialization of the shell to whether run in Batch
* ot Interactive mode. It also sends an error signal if there is
* an error occured while starting the shell.
*/
bool handle_mode(int argc, char** args);




#endif // SHELLCONTROLLER_H_INCLUDED
