#include "main.h"

/**
 * fill - fills standard output with string passed to it.
 *
 * @str: string passed to str.
 * Return: number of characters filled.
 */

int fill(char *str)
{
	int len, index;

	len = 0;
	index = 0;
	while (str[index] != '\0')
	{
		len++;
		_putchar(str[index]);
		index++;
	}

	return (len);
}
