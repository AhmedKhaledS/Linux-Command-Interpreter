#include "command_utils.h"
#include "Constants.h"
#include <string.h>
#ifndef COMMAND_PARSER_H_INCLUDED
#define COMMAND_PARSER_H_INCLUDED

struct command_properties* properties;
struct command_properties* parse(char** command);
void handle_comment(char** command);
void handle_foreground(char** command);

#endif // COMMAND_PARSER_H_INCLUDED
