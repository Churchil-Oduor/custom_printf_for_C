#include <stdlib.h>
#include "main.h"

int int_len(int data);
/**
 * int_toString - writes integer values onto terminal.
 *
 * @data: passed integer.
 * Return: index for __printf to proceed filling.
 */

char *int_toString(int data)
{
	char *table = "0123456789";
	char *rev_str, *str, ch;
	int len, x, val, sign, start;


	len = int_len(data);
	sign = 0;
	start = 0;

	if (data < 0)
	{
		len += 1;
		sign = 1;
	}

	str = (char *)malloc(sizeof(char) * (len + 1));
	rev_str = (char *)malloc(sizeof(char) * len);

	if (str == NULL || rev_str == NULL)
		return (NULL);

	if (sign == 1)
	{
		rev_str[0] = '-';
		start = 1;
	}

	for (x = start; x < len; x++)
	{
		val = data % 10;
		data /= 10;
		rev_str[x] = table[val];
	}

	for (x = len - 1; x >= 0; x--)
	{
		str[x] = rev_str[len - 1 - x];
	}
	str[len] = '\0';

	free(rev_str);
	return (str);
}

int int_len(int data)
{
	int len;

	len = 0;
	while (data)
	{
		data /= 10;
		len++;
	}

	return (len);
}

