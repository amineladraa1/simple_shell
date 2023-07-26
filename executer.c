#include "shell.h"

/**
 * execute - execute the commands
 *
 * @cmd: command entered by user
 *
 * @args: vector of arguments
 *
 * Return: void
 */

void execute(char *cmd, char **args)
{
	pid_t c_pid;
	int status;
	char **envi = environ;

	c_pid = fork();
	if (c_pid < 0)
		perror(cmd);
	if (c_pid == 0)
	{
		execve(cmd, args, envi);
		perror(cmd);
		free(cmd);
		free_b(args);
		exit(98);
	}
	else
		wait(&status);
}

