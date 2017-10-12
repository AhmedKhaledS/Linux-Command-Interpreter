#include "logger.h"



FILE* open_logging_file()
{
    log_file = open_log_file(&log_file);
}


void log(char* msg)
{
    log_msg(&log_file, msg, (int)getpid());
}

void log_child_process(int sig)
{
    log_child_msg(&log_file, "Child process is terminated successfully.", (int)getpid());
}

void report_error(char* msg)
{
    log_msg(&log_file, msg);
}

void close_logging_file()
{
    close_log_file(&log_file);
}
