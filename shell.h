#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

#define DELIM " \t\r\n\a"
#define BUFSIZE 1024

extern char **environ;

/**
 * builtins - a struct to track builtins commands
 *
 * @env: first builtin command
 * @exit: second builtin command
 *
 */

typedef struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * state - a state that contains information about the shell.
 *
 * @f_exit: exit.
 * @count: count of the executed command lines.
 *
 */

typedef struct state
{
	int f_exit;
	int count;
} state;

/**
 * struct flags - Represents various flags used by the shell.
 * @interactive: Flag indicating whether the shell is in interactive mode.
 */

struct flags
{
    bool interactive;
};

extern struct flags flg;

/* string_helpers */
void string_pr(char *s);
int _putchar(char s);
int _strlen(char *str);
char *_strchr(char *str, char ch);
char *_strdup(char *str);
int _strncmp(char *src, char *cmp, int n);
int _strcmp(char *str1, char *str2);

/* shell prototypes*/
char **_strtok(char *line);
void execute(char *cmd, char **args);
int main(int ac, char **av, char *env[]);

/* helper functions */
void exit_func(char **args, char *line);
void free_b(char **buf);
char *_getpath(void);
char *path_checker(char **path, char *command);
int builtins(char **args, char *line);
int builtin_checker(char **args, char *buffer);
char *cat_path(char *path, char *cmd);
void signal_handler(int num);
void user_input(void);
void env_print(void);

#endif /* SHELL_H */
