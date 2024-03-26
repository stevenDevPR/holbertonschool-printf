#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * handle_format - function for formats
 * @format: specifier
 * @args: arguments
 * Return: len
 */
int handle_format(const char *format, va_list args) {
    int len = 0;
    switch (*(format)) {
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

/**
 * print_int - Print an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_int(int n)
{
    return printf("%d", n);
}

/**
 * print_uint - Print an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_uint(unsigned int n)
{
    return printf("%u", n);
}

/**
 * print_octal - Print an octal number
 * @n: The number to print in octal format
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int n)
{
    return printf("%o", n);
}

/**
 * print_hex - Print a hexadecimal number
 * @n: The number to print in hexadecimal format
 * @uppercase: Whether to use uppercase letters (1) or not (0)
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    if (uppercase)
        return printf("%X", n);
    else
        return printf("%x", n);
}

/**
 * print_char - Print a single character
 * @c: The character to print
 */
void print_char(char c)
{
    putchar(c);
}

/**
 * print_string - Print a string
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int print_string(const char *str)
{
    if (str)
        return printf("%s", str);
    else
        return printf("(null)");
}

/**
 * print_pointer - Print a pointer address
 * @ptr: The pointer address to print
 *
 * Return: Number of characters printed
 */
int print_pointer(void *ptr)
{
    return printf("%p", ptr);
}

/**
 * print_percent - Print a percent sign
 *
 * Return: Always returns 1 (the length of the percent sign)
 */
int print_percent()
{
    putchar('%');
    return 1;
}
