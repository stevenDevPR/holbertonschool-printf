#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * handle_format - function for formats
 * @format: specifier
 * @args: arguments
 * Return: len
 */
int handle_format(const char *format, va_list args)
{
	int len = 0;

	switch (*(format))
	{
		case 'd':
		case 'i':
			len += print_int(va_arg(args, int));
			break;
		case 'u':
			len += print_uint(va_arg(args, unsigned int));
			break;
		case 'o':
			len += print_octal(va_arg(args, unsigned int));
			break;
		case 'x':
			len += print_hex(va_arg(args, unsigned int), 0);
			break;
		case 'X':
			len += print_hex(va_arg(args, unsigned int), 1);
			break;
		case 'c':
			print_char(va_arg(args, int));
			len++;
			break;
		case 's':
			len += print_string(va_arg(args, const char *));
			break;
		case 'p':
			len += print_pointer(va_arg(args, void *));
			break;
		case '%':
			len += print_percent();
			break;
		default:
			print_char('%');
			print_char(*format);
			len += 2;
			break;
	}
	return (len);
}
