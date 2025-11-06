#include "shell.h"

/**
 * find_path - Finds the full path of a command
 * @command: Command to search for
 *
 * Return: Pointer to full path string or NULL if not found
 */
char *find_path(char *command)
{
   char *path_env = getenv("PATH");
    char *path_copy, *dir, *full_path;
    struct stat st;
    size_t len;

    if (!path_env)
        return NULL;

    if (command[0] == '/' || command[0] == '.')
    {
        if (stat(command, &st) == 0)
            return strdup(command);
        else
            return NULL;
    }

    path_copy = strdup(path_env);
    dir = strtok(path_copy, ":");
    while (dir)
    {
        len = strlen(dir) + strlen(command) + 2;
        full_path = malloc(len);
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, len, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
