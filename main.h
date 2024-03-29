#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int handle_format(const char *format, va_list args);
int print_int(int n);
int print_uint(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
void print_char(char c);
int print_string(const char *str);
int print_pointer(void *ptr);
int print_percent(void);
int printf_reversed_string(const char *s);

#endif
