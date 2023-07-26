#include "shell.h"

/**
* tokenizer - creates a tokens from given input line
* @line: line be tokenized
* Return: array of strings
*/

char **_strtok(char *line)
{
char *buffer = NULL, *bufferp = NULL, *token = NULL, *delimiters = " :\t\r\n";
	char **tokens = NULL;
	int toksize = 1;
	size_t i = 0, flag = 0;

	buffer = _strdup(line);
	if (!buffer)
	return (NULL);
	bufferp = buffer;

	while (*bufferp)
	{
	if (_strchr(delimiters, *bufferp) != NULL && flag == 0)
	{
	toksize++;
	flag = 1;
	}
	else if (_strchr(delimiters, *bufferp) == NULL && flag == 1)
	flag = 0;
	bufferp++;
	}
	tokens = malloc(sizeof(char *) * (toksize + 1));
	token = strtok(buffer, delimiters);
	while (token)
	{
	tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
		free(tokens);
		return (NULL);
		}
	token = strtok(NULL, delimiters);
	i++;
	}
	tokens[i] = '\0';
	free(buffer);
	return (tokens);
}
