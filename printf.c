#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	va_start(args, format);

	if (!format)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				len += print_percent();
				format += 2;
				continue;
			}
			else if (*(format + 1) == '\0')
			{
				va_end(args);
				return (-1);
			}
			else
			{
				format++;
				len += handle_format(format, args);
			}
		}
		else
		{
			print_char(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
