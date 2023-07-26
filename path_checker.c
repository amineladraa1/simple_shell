#include "shell.h"

/**
* path_checker - find path in directories
*
* @path: path env 
*
* @command: user command
*
* Return: full_path (success) NULL (failure)
*/

char *path_checker(char **path, char *command)
{
	int i = 0;
	char *full_cmd;

	while (path[i])
	{
		full_cmd = cat_path(path[i], command);
		if (access(full_cmd, F_OK | X_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (NULL);
}
