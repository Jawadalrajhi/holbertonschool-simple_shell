#include "shell.h"

/**
 * count_words - counts words separated by spaces
 * @s: input string
 *
 * Return: number of words
 */
int count_words(char *s)
{
	int count = 0;

	while (*s)
	{
		while (*s && *s == ' ')
			s++;

		if (*s)
			count++;

		while (*s && *s != ' ')
			s++;
	}

	return (count);
}

/**
 * parse_cmd - splits input into command + arguments
 * @cmd: pointer to command string
 * @args: pointer to array of arguments
 * @input: input line
 *
 * Return: 0 on success, -1 on failure
 */
int parse_cmd(char **cmd, char ***args, char *input)
{
	int i = 0, words;
	char *token;

	words = count_words(input);
	if (words == 0)
		return (-1);

	*args = malloc(sizeof(char *) * (words + 1));
	if (!*args)
		return (-1);

	token = strtok(input, " ");
	while (token)
	{
		(*args)[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	(*args)[i] = NULL;

	*cmd = (*args)[0];
	return (0);
}

/**
 * free_args - frees the array of arguments
 * @args: pointer to args array
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}

	free(args);
}

