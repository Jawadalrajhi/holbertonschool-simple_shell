#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char *input;
    char **args;

    while (1)
    {
        display_prompt();
        input = read_input();
        if (!input)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0)
        {
            free(input);
            continue;
        }

        args = tokenize_input(input);
        if (args && args[0])
        {
            if (handle_builtin(args) == 0)
                execute_command(args);
        }

        free_tokens(args);
        free(input);
    }

    return (0);
}
