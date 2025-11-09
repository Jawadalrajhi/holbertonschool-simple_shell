#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/* Function prototypes */
void display_prompt(void);
char *read_input(void);
void execute_command(char **args);
char *find_path(char *command);
int handle_builtin(char **args);
char **tokenize_input(char *input);
void free_tokens(char **tokens);

#endif /* SHELL_H */
