#include "main.h"
#include <stdio.h>
#include <string.h>
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
		return (printf("%s", str));
	else
		return (printf("(null)"));
}

/**
 * print_pointer - Print a pointer address
 * @ptr: The pointer address to print
 *
 * Return: Number of characters printed
 */
int print_pointer(void *ptr)
{
	return (printf("%p", ptr));
}

/**
 * print_percent - Print a percent sign
 *
 * Return: Always returns 1 (the length of the percent sign)
 */
int print_percent(void)
{
	putchar('%');
	return (1);
}
