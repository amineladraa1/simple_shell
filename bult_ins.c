#include "shell.h"

/**
* builtins - execute built ins functions
*
* @args : user command
* @line : line read from user
*
* Return: 1 (success) 0 (faillure)
*/

int builtins(char **args, char *line)
{
	struct built b = {"env", "exit"};

	if (_strcmp(*args, b.env) == 0)
	{
		env_print();
		return (1);
	}
	else if (_strcmp(*args, b.exit) == 0)
	{
		exit_func(args, line);
		return (1);
	}
	return (0);
}

/**
* builtin_checker - looks for builtins functions
*
* @args: cmd from user
*
* @line: buffer that contains getline
*
* Return: 1 (success) 0 (faillure)
*/

int builtin_checker(char **args, char *line)
{
	if (builtins(args, line))
		return (1);
	else if (**args == '/')
	{
		execute(args[0], args);
		return (1);
	}
	return (0);
}
