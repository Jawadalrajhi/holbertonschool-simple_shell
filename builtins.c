#include "shell.h"

/**
 * handle_builtin - Handles built-in commands like exit and env
 * @args: Array of command arguments
 *
 * Return: 1 if a built-in command was executed, 0 otherwise
 */
int handle_builtin(char **args)
{
    int i;

    if (args[0] == NULL)
        return (0);

    /* Built-in: exit */
    if (strcmp(args[0], "exit") == 0)
    {
        free_tokens(args);
        exit(0);
    }

    /* Built-in: env */
    if (strcmp(args[0], "env") == 0)
    {
        for (i = 0; environ[i]; i++)
            printf("%s\n", environ[i]);
        return (1);
    }

    return (0);
}
