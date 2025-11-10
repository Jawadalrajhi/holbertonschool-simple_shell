#include "shell.h"

/**
 * fetch_env_value - retrieves the value of a given environment variable
 * @name: the variable name to look for
 * @env: the environment variables array
 *
 * Return: pointer to the variable value, or NULL if not found
 */
char *fetch_env_value(char *name, char **env)
{
	int i = 0, j;
	char *ptr;

	if (!name || !env)
		return (NULL);

	while (env[i])
	{
		ptr = env[i];
		j = 0;

		while (*ptr && name[j] && name[j] == *ptr)
		{
			ptr++;
			j++;
			if (*ptr == '=' && name[j] == '\0')
				return (ptr + 1);
		}
		i++;
	}

	return (NULL);
}

/**
 * shell_non_interactive - checks if the shell runs in non-interactive mode
 *
 * Return: 1 if non-interactive, otherwise 0
 */
int shell_non_interactive(void)
{
	return (!isatty(STDIN_FILENO));
}

/**
 * str_is_numeric - checks if a given string contains only digits
 * @s: string to check
 *
 * Return: 1 if the string is numeric, otherwise 0
 */
int str_is_numeric(char *s)
{
	if (*s == '\0')
		return (1);

	if (*s < '0' || *s > '9')
		return (0);

	return (str_is_numeric(s + 1));
}

