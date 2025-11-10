#include "shell.h"

/**
 * display_prompt - prints the shell prompt
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * get_cmd - reads input from stdin
 * @buffer: pointer to store input string
 * @size: pointer to buffer size
 *
 * Return: 0 on success, -1 on failure
 */
int get_cmd(char **buffer, size_t *size)
{
	ssize_t read_bytes;

	read_bytes = getline(buffer, size, stdin);

	if (read_bytes == -1)
		return (-1);

	if ((*buffer)[read_bytes - 1] == '\n')
		(*buffer)[read_bytes - 1] = '\0';

	return (0);
}

