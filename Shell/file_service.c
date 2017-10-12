#include "file_service.h"

const int MAX_COMMANDS = 500;
const int MAX_LEN = 513;

void save_history()
{
    FILE* file;
    char tmp[MAX_LEN];
    strcpy(tmp, shell_directory);
    file = fopen(strcat(tmp,"/history.txt"), "a+");
    if (file == NULL)
        return;
    fputs(history[command_counter-1], file);
    fputs("\n", file);
    fclose(file);
}

void load_history()
{
    FILE* file;
    char tmp[MAX_LEN];
    strcat(tmp, shell_directory);
    file = fopen(strcat(tmp,"/history.txt"), "r+");
    if (file == NULL)
        return;
    char buffer[MAX_COMMANDS][MAX_LEN];
    while (fgets(buffer[command_counter], MAX_LEN, file) != NULL)
    {
        add_command(buffer[command_counter]);
    }
    fclose(file);
}

FILE* open_log_file(FILE *file)
{
    char tmp[MAX_LEN];
    strcat(tmp, shell_directory);
    file = fopen(strcat(tmp, "/log.txt"), "a+");
    return file;
}

void log_msg(FILE *file, char* msg, int pid)
{
    time_t rawTime;
    struct tm *info;
    char buff[80];
    char tmp[MAX_LEN];
    strcpy(tmp, shell_directory);
    time(&rawTime);
    info = localtime(&rawTime);
    strftime(buff, 80, "%x - %I:%M%p", info);
    file = fopen(strcat(tmp, "/log.txt"), "a+");
    if (file == NULL)
        return;
    fprintf(file, "[%d] %s[DEBUG]: %s\n",pid, buff, msg);
    fclose(file);
}

void log_child_msg(FILE *file, char *msg, int pid)
{
    time_t rawTime;
    struct tm *info;
    char buff[80];
    char tmp[MAX_LEN];
    strcpy(tmp, shell_directory);
    time(&rawTime);
    info = localtime(&rawTime);
    strftime(buff, 80, "%x - %I:%M%p", info);
    file = fopen(strcat(tmp, "/log.txt"), "a+");
    if (file == NULL)
        return;
    fprintf(file, "[%d] %s[DEBUG]: %s\n",pid, buff, msg);
    fclose(file);
}

void close_log_file(FILE *file)
{
   // fclose(file);
}
