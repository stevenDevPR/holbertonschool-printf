#include "main.h"

int simple_sentence(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*str)
	{
		_putchar(*format);
		count++;
	}

	va_end(args);
	return (count);
}
