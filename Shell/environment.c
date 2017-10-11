#include "environment.h"

void setup_environment()
{
    chdir(getenv("HOME"));
}
