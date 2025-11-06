#include "shell.h"

/**
 * handle_exit - Handles the built-in exit command
 * @input: User input string
 *
 * Return: void
 */
void handle_exit(char *input)
{
   free(input);
    exit(0);
}

/**
 * handle_env - Handles the built-in env command
 *
 * Return: void
 */
void handle_env(void)
{
    int i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
