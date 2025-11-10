#include "shell.h"

/**
 * execute_child - runs the command inside the child process
 * @full_path: executable full path
 * @argv: arguments list
 * @env: environment variables
 * @cmd: command name for perror
 */
void execute_child(char *full_path, char **argv, char **env, char *cmd)
{
	if (execve(full_path, argv, env) == -1)
	{
		perror(cmd);
		exit(127);
	}
}

/**
 * wait_for_child - waits and handles exit status
 * @full_path: allocated path to free if needed
 * @cmd: command name
 *
 * Return: exit status
 */
int wait_for_child(char *full_path, char *cmd)
{
	int status;

	wait(&status);

	if (full_path != cmd)
		free(full_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (-1);
}

/**
 * execute - handles execution (fork, exec, wait)
 * @cmd: command name
 * @env: environment
 * @argv: arguments list
 * @line_num: line number for error output
 * @prog_name: program name
 *
 * Return: exit status
 */
int execute(char *cmd, char **env, char **argv, int line_num, char *prog_name)
{
	pid_t pid;
	char *full_path;

	if (!cmd || !*cmd)
		return (0);

	full_path = get_full_path(cmd, env);
	if (!full_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", prog_name, line_num, cmd);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		return (-1);
	}
	else if (pid == 0)
	{
		execute_child(full_path, argv, env, cmd);
	}

	return (wait_for_child(full_path, cmd));
}

/**
 * is_in_path - checks if command exists in PATH
 * @cmd: command
 * @env: environment
 *
 * Return: 1 if exists, 0 if not
 */
int is_in_path(char *cmd, char **env)
{
	char *path_env, *copy, *dir, *tmp;

	if (!cmd)
		return (0);

	if (strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (1);

	path_env = fetch_env_value("PATH", env);
	if (!path_env)
		return (0);

	copy = strdup(path_env);
	if (!copy)
		return (0);

	dir = strtok(copy, ":");
	while (dir)
	{
		tmp = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!tmp)
		{
			free(copy);
			return (0);
		}

		sprintf(tmp, "%s/%s", dir, cmd);

		if (access(tmp, X_OK) == 0)
		{
			free(tmp);
			free(copy);
			return (1);
		}
		free(tmp);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (0);
}

/**
 * get_full_path - builds full executable path
 * @cmd: command
 * @env: environment
 *
 * Return: malloc'd full path or NULL
 */
char *get_full_path(char *cmd, char **env)
{
	char *path_env, *copy, *dir, *full;

	if (!cmd)
		return (NULL);

	if (strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (strdup(cmd));

	path_env = fetch_env_value("PATH", env);
	if (!path_env)
		return (NULL);

	copy = strdup(path_env);
	if (!copy)
		return (NULL);

	dir = strtok(copy, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
		{
			free(copy);
			return (NULL);
		}

		sprintf(full, "%s/%s", dir, cmd);

		if (access(full, X_OK) == 0)
		{
			free(copy);
			return (full);
		}

		free(full);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}
