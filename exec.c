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
    char *argv[2];

    if (access(command, X_OK) != 0)
    {
        fprintf(stderr, "%s: command not found\n", command);
        return;
    }

    pid = fork();
    if (pid == 0)
    {
        argv[0] = command;
        argv[1] = NULL;
        execve(command, argv, environ);
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
}
