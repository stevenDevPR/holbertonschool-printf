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
	int len = 0; //len nos va sumando cantidad de caracteres
	va_list args; //variable de los argumentos

	va_start(args, format); //se inicializa variable de argumentos

	if (!format) //verificamos que el string format no es nulo
		return (-1); //si es NULL retorna -1

	while (*format) //loop donde iteramos en cada carácter en el string format
	{
		if (*format == '%') //se verifica si el caracter es %
		{
			if (*(format + 1) == '%') //se verifica siguiente caracter al lado
			{
				len += print_percent(); //se imprime literal el signo %
				format += 2; //hacemos skip al signo de porciento
				continue;
			}
			else if (*(format + 1) == '\0') //verificamos que no sea NULL luego del primer %
			{
				va_end(args); //si es NULL liberamos args
				return (-1); //retorna -1 format specifier incompleto
			}
			else //si no es NULL o no es el signo de porciento haz esto
			{
				format++; //nos movemos luego del signo %
				len += handle_format(format, args);//utilizamos funcion handle_format pra deteminar 
			}
		}
		else //si al iterar no hay % incial
		{
			print_char(*format); // se imprime el carácter normal
			len++; //incrementamos len
		}
		format++; //nos movemos the caracter en format string
	}
	va_end(args); //liberamos args
	return (len); //se retorna la cantidad total de caracteres
}
