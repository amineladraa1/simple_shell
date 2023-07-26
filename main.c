#include "shell.h"
/**
* main - Entry point of the program
*
* @ac: argument count
* @av: argument vector
* @env: environment vector
*
* Return: 0 (success)
*/


int main(int ac, char **av, char *env[])
{
	struct flags flg = {0};
	struct state stt;
	char *line = NULL, *pathcmd = NULL, *p = NULL;
	size_t buffersize = 0;
	ssize_t len = 0;
	char **args = NULL, **paths = NULL;
	(void)env, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, signal_handler);
	while (1)
	{
		free_b(args);
		free_b(paths);
		free(pathcmd);
		user_input(&flg);
		len = getline(&line, &buffersize, stdin);
		if (len < 0)
			break;
		stt.count++;
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		args = _strtok(line);
		if (args == NULL || *args == NULL || **args == '\0')
			continue;
		if (builtin_checker(args, line))
			continue;
		p = _getpath();
		paths = _strtok(p);
		pathcmd = path_checker(paths, args[0]);
		if (!pathcmd)
			perror(av[0]);
		else
			execute(pathcmd, args);
	}
	if (len < 0 && flg.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
