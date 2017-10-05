#include "Constants.h"
#include "command_utils.h"
#ifndef COMMAND_PARSER_H_INCLUDED
#define COMMAND_PARSER_H_INCLUDED

struct command_properties* properties;
struct command_properties* parse(char** command);


#endif // COMMAND_PARSER_H_INCLUDED
