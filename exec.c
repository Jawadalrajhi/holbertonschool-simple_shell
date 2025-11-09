#include "shell.h"

/**
 * execute_command - Executes a given command
 * @args: Array of command arguments
 *
 * Return: void
 */
void execute_command(char **args)
{
    pid_t pid;
    int status;
    char *path;

    if (args == NULL || args[0] == NULL)
        return;

    path = find_path(args[0]);
    if (path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    if (access(path, X_OK) != 0)
    {
        fprintf(stderr, "%s: Permission denied\n", args[0]);
        free(path);
        return;
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(path, args, environ) == -1)
        {
            perror("execve");
            free(path);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    free(path);
}
