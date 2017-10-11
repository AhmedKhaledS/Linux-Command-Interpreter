#include "logger.h"



FILE* open_logging_file()
{
    log_file = open_log_file(&log_file);
}


void log(char* msg)
{
    log_msg(&log_file, msg);
}

void report_error(char* msg)
{
    log_msg(&log_file, msg);
}

void close_logging_file()
{
    close_log_file(&log_file);
}
