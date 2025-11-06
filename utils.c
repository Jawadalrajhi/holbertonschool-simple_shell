#include "shell.h"

char *read_input(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&input, &len, stdin);
    if (nread == -1)
    {
        free(input);
        return NULL;
    }
    return input;
}
/**
 * tokenize_input - Splits input string into tokens
 * @input: The input string to split
 *
 * Return: Array of token strings
 */
char **tokenize_input(char *input)
{
     char **tokens = NULL;
    char *token;
    size_t count = 0;

    token = strtok(input, " \t");
    while (token)
    {
        tokens = realloc(tokens, sizeof(char *) * (count + 2));
        if (!tokens)
            return NULL;

        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, " \t");
    }

    if (tokens)
        tokens[count] = NULL;

    return tokens;
}

/**
 * free_tokens - Frees memory allocated for tokens
 * @tokens: Array of strings to free
 *
 * Return: void
 */
void free_tokens(char **tokens)
{
    size_t i = 0;
    if (!tokens)
        return;

    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
}
