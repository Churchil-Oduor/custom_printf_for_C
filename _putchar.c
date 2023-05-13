#include <unistd.h>

void _putchar(char data)
{
	write(1, &data, 1);
}

