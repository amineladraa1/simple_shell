#include "shell.h"

/**
 * _strncmp - compare 2 strings with n char
 *
 * @src: first string to compare
 *
 * @cmp: second string to compare
 *
 * @n: number of bytes
 *
 * Return: difference (success) 0 (failure)
 */
int _strncmp(char *src, char *cmp, int n)
{
	int j;

	for (j = 0; src[j] && cmp[j] && j < n; j++)
	{
		if (src[j] != cmp[j])
		return (src[j] - cmp[j]);
	}
	return (0);
}

/**
 * _strcmp - compare 2 strings
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: 1 or -1 or 0
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
	if (*str1 != *str2)
	{
		return ((*str1 < *str2) ? -1 : 1);
	}
	str1++;
	str2++;
	}
	return (0);
}

/**
* string_pr - string printer.
*
* @s: string to be printed.
*
* Return : void
*/

void string_pr(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	_putchar(s[i]);
	}
}
