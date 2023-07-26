#include "shell.h"

/**
 * env_print - print the environement variable
 *
 * Return: void
 */

void env_print(void)
{
	int j;
	char **envi = environ;

	for (j = 0; envi[j]; j++)
	{
		write(STDOUT_FILENO, envi[j], _strlen(envi[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
}


/**
 * _getpath - get the path
 *
 * Return: path (success) NULL (failure)
 */

char *_getpath(void)
{
	int i = 0;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
		return (path);
		}
		env++;
	}
	return (NULL);
}

/**
* cat_path - append the cmd to the path
*
* @path: path
* @cmd: user cmd
*
* Return: buffer (success) NULL (failure)
*/

char *cat_path(char *path, char *cmd)
{
	char *line;
	size_t i, j;

	if (cmd == 0)
		cmd = "";
	if (path == 0)
		path = "";

	line = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));

	if (!line)
		return (NULL);

	for (i = 0; path[i]; i++)
		line[i] = path[i];

	if (path[i - 1] != '/')
	{
		line[i] = '/';
		i++;
	}
	for (j = 0; cmd[j]; j++)
		line[i + j] = cmd[j];
	line[i + j] = '\0';
	return (line);
}
