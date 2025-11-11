#include "shell.h"

/**
 * main - Entry point of the shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: exit status
 */
int main(int ac, char **av, char **env)
{
	char *input = NULL, *cmd = NULL;
	char **args = NULL;
	size_t size = 0;
	int line_num = 0, status = 0;

	(void)ac;

	while (1)
	{
		args = NULL;
		line_num++;

		if (isatty(STDIN_FILENO))
			display_prompt();

		if (get_cmd(&input, &size) == -1)
			break;

		if (parse_cmd(&cmd, &args, input) == -1)
			continue;

		if (is_internal_command(cmd))
		{
			status = run_internal(cmd, args, env);
			if (status == SHELL_EXIT_SIGNAL)
			{
				free_args(args);
				break;
			}
		}
		else
		{
			status = execute(cmd, env, args, line_num, av[0]);
		}

		free_args(args);
	}

	free(input);
	return (status == SHELL_EXIT_SIGNAL ? 0 : status);
}
