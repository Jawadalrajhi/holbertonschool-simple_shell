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

        /* إزالة المسافات */
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0)
        {
            free(input);
            continue;
        }

        if (strcmp(input, "exit") == 0)
        {
            handle_exit(input);
        }

        if (strcmp(input, "env") == 0)
        {
            handle_env();
            free(input);
            continue;
        }

        args = tokenize_input(input);
        if (args && args[0])
            execute_command(args[0]);

        free_tokens(args);
        free(input);
    }

    return 0;
}
