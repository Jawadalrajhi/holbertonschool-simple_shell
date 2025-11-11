#include "shell.h"

/**
 * exit_shell - handles the exit built-in command
 * @args: argument array (may contain exit status)
 * @env: environment variables (unused)
 *
 * Return: SHELL_EXIT_SIGNAL or exit status
 */
int exit_shell(char **args, char **env)
{
	int exit_status = last_status;

	(void)env;

	/* handle case: exit with numeric argument */
	if (args[1] != NULL)
	{
		if (str_is_numeric(args[1]))
			exit_status = atoi(args[1]);
		else
		{
			fprintf(stderr, "exit: Illegal number: %s\n", args[1]);
			exit_status = 2; /* mimic bash behavior */
		}
	}

	exit(exit_status);
}

/**
 * show_env - prints all environment variables
 * @args: arguments (unused)
 * @env: environment variables
 *
 * Return: Always 0
 */
int show_env(char **args, char **env)
{
	int i = 0;

	(void)args;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

/**
 * is_internal_command - checks if a command is a built-in
 * @cmd: command name
 *
 * Return: 1 if built-in, 0 otherwise
 */
int is_internal_command(char *cmd)
{
	int i;
	static builtin_cmd command_table[] = {
		{"env", show_env},
		{"exit", exit_shell},
	};

	for (i = 0; i < (int)(sizeof(command_table) / sizeof(command_table[0])); i++)
	{
		if (strcmp(command_table[i].name, cmd) == 0)
			return (1);
	}
	return (0);
}

/**
 * run_internal - executes a built-in command
 * @cmd: command name
 * @args: arguments
 * @env: environment variables
 *
 * Return: status or SHELL_EXIT_SIGNAL
 */
int run_internal(char *cmd, char **args, char **env)
{
	int i;
	static builtin_cmd command_table[] = {
		{"env", show_env},
		{"exit", exit_shell},
	};

	for (i = 0; i < (int)(sizeof(command_table) / sizeof(command_table[0])); i++)
	{
		if (strcmp(command_table[i].name, cmd) == 0)
			return (command_table[i].func(args, env));
	}
	return (127);
}
