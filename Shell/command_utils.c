#include "command_utils.h"
#include "stdbool.h"

struct command_properties
{
    char* type;
    char** arguments;
    bool foreground;
};
