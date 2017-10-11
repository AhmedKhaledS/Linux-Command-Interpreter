#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"

FILE *log_file;
FILE* open_logging_file();
void log(char* msg);
void report_error(char* msg);
void close_logging_file();

#endif // LOGGER_H_INCLUDED
