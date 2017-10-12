#include "environment.h"

void setup_environment()
{
    chdir(getenv("HOME"));
    getcwd(shell_directory, sizeof(shell_directory));
}
