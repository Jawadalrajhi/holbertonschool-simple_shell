#include "shell.h"

/* List of available built-in commands */
static builtin_cmd command_table[] = {
	{"env", show_env},
	{"exit", exit_shell},
	/* Add more built-ins here if needed */
};

/**
 * is_internal_command - checks if a command is built-in
 * @cmd: command name
 *
 * Return: 1 if built-in, 0 otherwise
 */
int is_internal_command(char *cmd)
{
	int i;

	for (i = 0; i < (int)(sizeof(command_table) / sizeof(command_table[0])); i++)
	{
		if (strcmp(command_table[i].name, cmd) == 0)
			return (1);
	}
	return (0);
}

/**
 * run_internal - runs a built-in command if available
 * @cmd: command name
 * @args: arguments
 * @env: environment variables
 *
 * Return: status code from the built-in command
 */
int run_internal(char *cmd, char **args, char **env)
{
	int i;

	for (i = 0; i < (int)(sizeof(command_table) / sizeof(command_table[0])); i++)
	{
		if (strcmp(command_table[i].name, cmd) == 0)
			return (command_table[i].func(args, env));
	}
	return (127);
}

/**
 * show_env - prints environment variables
 * @args: command arguments (unused)
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
 * exit_shell - exits the shell
 * @args: command arguments (unused)
 * @env: environment variables (unused)
 *
 * Return: does not return
 */
int exit_shell(char **args, char **env)
{
	(void)args;
	(void)env;

	exit(last_status);
}

