#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * print_int - Print an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_int(int n)
{
	return (printf("%d", n));
}

/**
 * print_uint - Print an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_uint(unsigned int n)
{
	return (printf("%u", n));
}

/**
 * print_octal - Print an octal number
 * @n: The number to print in octal format
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int n)
{
	return (printf("%o", n));
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
		return (printf("%X", n));
	else
		return (printf("%x", n));
}
