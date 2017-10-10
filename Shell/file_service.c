#include "file_service.h"

const int MAX_COMMANDS = 500;
const int MAX_LEN = 513;

void save_history()
{
    FILE* file;
    file = fopen("history.txt", "w");
    for (int line = 0; line < command_counter; line++)
    {
        fputs(history[line], file);
        fputc('\n', file);
    }
    fclose(file);
}

void load_history()
{
    FILE* file;
    if (access("history.txt", F_OK) != -1)
    {
        file = fopen("history.txt", "r");
        char buffer[MAX_COMMANDS][MAX_LEN];
        while (fgets(buffer[command_counter], MAX_LEN, file) != NULL)
        {
            add_command(buffer[command_counter]);
        }
        fclose(file);
    }
}
