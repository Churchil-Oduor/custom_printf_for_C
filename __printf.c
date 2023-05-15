#include <stdlib.h>
#include <stdarg.h>
#include "main.h"



int place_holder(char ch);
int get_total_holders(const char *format);
int valid_holder(char ch);
void **ptr_array(const char *format, va_list *list);

/**
 * __printf - custom C printf function.
 *
 * @format: format to be followed containing the place holders.
 * Return: total number of characters printed in stdout.
 */

int __printf(const char *format, ...)
{
	va_list list;
	int len, index, holder, int_val, holder_index;
	void *ptr, **holder_arr;

	int (*select_op[1])(void *data) = {write_int};
	va_start(list, format);
	len = 0;
	index = 0;

	holder_arr = ptr_array(format, &list);
	holder_index = 0;

	while (format[index] != '\0')
	{
		holder = place_holder(format[index + 1]);
		if (format[index] == '%' && holder >= 0)
		{
			len += select_op[holder](holder_arr[holder_index++]);
			index += 2;
		}
		else if (format[index] == '\n')
		{
			_putchar(format[index]);
			index++;
		}
		else
		{
			len++;
			_putchar(format[index]);
			index++;
		}
	}

	free(holder_arr);

	return (len);
}


/**
 * place_holder - checks the passed place holder character.
 *
 * @ch: character specifying place_holder type.
 * Return: index of function to be executed in the function array.
 */

int place_holder(char ch)
{
	if (ch == 'd')
		return (0);
	else
		return (-1);
}

/**
 * ptr_array - creates a void pointer array holding pointers of
 * arguments passed in variadic function.
 *
 * @format: string containig the sequence of arguments in variadic function
 * in form of place-holders.
 * @list: pointer to unknown arguments of variadic function.
 * Return: an array of void pointers.
 */

void **ptr_array(const char *format, va_list *list)
{
	va_list _list;
	void **ptr;
	int index, arr_index, total_holders;
	int *ptr_int, value_int;
	char *str, *ptr_char, value_char;

	va_copy(_list, *list);
	total_holders = get_total_holders(format);
	ptr = malloc(sizeof(void **) * total_holders);

	index = 0;
	arr_index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && valid_holder(format[index + 1]) == 1)
		{
			if (format[index + 1] == 'd')
			{
				value_int = va_arg(_list, int);
				ptr_int = &value_int;
				ptr[arr_index++] = (void *)ptr_int;
				index++;
			}
			else if (format[index + 1] == 's')
			{
				str = va_arg(_list, char *);
				ptr[arr_index++] = (void *)str;
				index++;
			}
			else if (format[index + 1] == 'c')
			{
				value_char = va_arg(_list, int) - '0';
				ptr_char = &value_char;
				ptr[arr_index++] = (void *)ptr_char;
				index++;
			}
			else
			{
				index++;
			}
		}
		else
		{
			index++;
		}
	}

	va_end(_list);
	return (ptr);


}


/**
 * get_total_holders - counts the total number of place holders in format.
 *
 * @format: string containing sequence of place-holders.
 * Return: total number of place holders.
 */

int get_total_holders(const char *format)
{
	int count, index;

	count = 0;
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && valid_holder(format[index + 1]) == 1)
			count++;
		++index;
	}

	return (count);

}

/**
 * valid_holder - checks if the place-holder character is valid.
 *
 * @ch: place-holder character to be checked.
 * Return: 1 if valid otherwise 0.
 */

int valid_holder(char ch)
{
	if (ch == 'c' || ch == 'd' || ch == 's')
		return (1);
	return (0);
}
