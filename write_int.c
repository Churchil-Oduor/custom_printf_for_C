#include <stdlib.h>
#include "main.h"

int int_len(int data);
/**
 * write_int - writes integers passed into standard output.
 *
 * @data: pointer to integer which has been voided.
 * Return: number of characters that have been written.
 */

int write_int(void *data)
{
	const char *table = "0123456789";
	char *rev_str;
	int *ptr;
	int int_val, len, is_negative, i;

	ptr = (int *)data;
	int_val = *ptr;
	len = int_len(int_val);
	is_negative = 0;

	if (int_val < 0)
		is_negative = 1;

	rev_str = malloc(sizeof(char *) * (len + is_negative));

	for (i = 0; i < len; i++)
	{
		rev_str[i] = table[int_val % 10];
		int_val /= 10;
	}

	if (is_negative)
		rev_str[len] = '-';

	for (i = 0; i < (len + is_negative); i++)
	{
		_putchar(rev_str[(len + is_negative) - i - 1]);
	}
	free(rev_str);

	return (len + is_negative);
}


/**
 * int_len - counts the number of digits in the number.
 *
 * @data: number whose digit count is sought.
 * Return: Number of digits in @data.
 */

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
