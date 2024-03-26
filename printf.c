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
	int len = 0, count = 0, ui;
	va_start(args, format);
	
	if (!format)
	{
		return (-1);
	}

	while (format && format[count])
	{
		if (format[count] == '%')
		{
			if (format[count + 1] == '%')
			{
				putchar('%');
				len++;
				count += 2;
				continue;
			}
			else if (format[count + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			else
			{
				count++;
			switch (format[count])
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
				case '\0':
					va_end(args);
					return (-1);
				default:
					putchar('%');
					putchar(format[count]);
					len += 2;
					break;
			}
		}
		}
		else
		{
			putchar(format[count]);
			len++;
		}
		count++;
	}

	va_end(args);

return len;
}
