#include "shell.h"

/**
 * execute_command - Executes a given command
 * @command: The command to execute
 *
 * Return: void
 */
void execute_command(char *command)
{
 pid_t pid;
    int status;
    char *path;
    char *argv[2];

    path = find_path(command);
    if (!path)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return;
    }

    pid = fork();
    if (pid == 0)
    {
        argv[0] = path;
        argv[1] = NULL;
        execve(path, argv, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork");
    }

    free(path);
}
