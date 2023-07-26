#include <unistd.h>
#include "shell.h"

/**
 * _putchar - writes the character c
 * @s: character to print
 *
 * Return: 1 (success) -1 (failure)
 */
int _putchar(char s)
{
	return (write(1, &s, 1));
}

/**
 * _strlen - return len of a string
 * @str: string to count
 *
 * Return: length
 */


int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
	len++;
	str++;
	}
	return (len);
}

/**
 * _strchr - finds a charachter in an array of strings
 *
 * @str: cstring to check
 * @ch: character to find
 * Return: the character if found, NULL (faillure)
 */

char *_strchr(char *str, char ch)
{
	while (*str != '\0')
	{
	if (*str == ch)
	{
	return (str);
	}
	str++;
	}
	return (NULL);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: the new string
 */

char *_strdup(char *str)
{
	int len, i;
	char *temp, *new_str;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	temp = str;
	while (*temp)
	{
	len++;
	temp++;
	}

	new_str = (char *)malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
	{
	return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}
