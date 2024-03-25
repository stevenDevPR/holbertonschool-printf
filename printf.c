#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, ui;
	if (!format)
	{
		return (0);
	}

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'd':
				case 'i':
					len += printf("%d", va_arg(args, int));
					break;
				case 'u':
					ui = va_arg(args, unsigned int);
					len += printf("%u", ui);
					break;
				case 'o':
					len += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					len += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					len += printf("%X", va_arg(args, unsigned int));
					break;
				case 'c':
					len += printf("%c", va_arg(args, int));
					break;
				case 's':
					len += printf("%s", va_arg(args, char *));
					break;
				case 'p':
					len += printf("%p", va_arg(args, void *));
					break;
				case '%':
					putchar('%');
					len++;
					break;
				default:
					putchar('%');
					putchar(*format);
					len += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);

return len;
}
