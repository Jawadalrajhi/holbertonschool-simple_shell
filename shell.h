#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct builtin_cmd - Struct for built-in commands
 * @name: command name
 * @func: function to execute the command
 */
typedef struct builtin_cmd
{
	char *name;
	int (*func)(char **args, char **env);
} builtin_cmd;

/* ======= Built-in Commands ======= */
int is_internal_command(char *cmd);
int run_internal(char *cmd, char **args, char **env);
int show_env(char **args, char **env);
int str_to_int(char *s, char *prog_name);
int exit_shell(char **args, char **env);

/* ======= Execution ======= */
int execute(char *cmd, char **env, char **argv, int line_num, char *prog_name);
int wait_for_child(char *full_path, char *cmd);
void execute_child(char *full_path, char **argv, char **env, char *cmd);
int is_in_path(char *cmd, char **env);
char *get_full_path(char *cmd, char **env);

/* ======= Parsing ======= */
int count_words(char *s);
void free_args(char **args);
int parse_cmd(char **cmd, char ***args, char *input);
int get_cmd(char **buffer, size_t *size);

/* ======= Utilities ======= */
char *fetch_env_value(char *name, char **env);
int shell_non_interactive(void);
int str_is_numeric(char *s);

/* ======= Input / Output ======= */
void display_prompt(void);
char *read_input(void);

#endif /* SHELL_H */

