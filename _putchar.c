#include <unistd.h>

/**
 * _putchar - prints characters onto screen.
 *
 * @data: data to be printed.
 * Return: nothing.
 */

void _putchar(char data)
{
	write(1, &data, 1);
}

