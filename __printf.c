#include <stdarg.h>
#include "main.h"

/**
 * __printf - custom C printf function.
 *
 * @format: format to be followed containing the place holders.
 * Return: total number of characters printed in stdout.
 */

int __printf(const char *format, ...)
{
	va_list list;
	int len, index;

	va_start(list, format);
	len = 0;
	index = 0;

	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == 'd')
		{
			len += fill(int_toString(va_arg(list, int)));
			index += 2;
		}
		else
		{
			if (format[index] != '\n')
				len++;
			_putchar(format[index]);
			index++;
		}
	}

	return (len);
}
