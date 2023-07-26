#include "shell.h"

/**
 * free_b - frees given buffer
 *
 * @buf: buffer to free
 *
 * Return: void
 */

void free_b(char **buf)
{
	int i;

	if (!buf || buf == NULL)
		return;
	for (i = 0; buf[i]; i++)
		free(buf[i]);
	free(buf);
}

/**
* exit_func - execute the exit cmd
*
* @args: user commands
* @line: read from readline
*
* Return: void
*/

void exit_func(char **args, char *line)
{
	free(line);
	free_b(args);
	exit(0);
}

/**
 * signal_handler - callback function to signal
 *
 * @num: number given by signal
 *
 * Return: void
 */

void signal_handler(int num)
{
	(void)num;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

/**
* user_input - check interactive mode and print the $
*
* Return: void
*/

void user_input(void)
{

	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
		flg.interactive = 1;

	if (flg.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
