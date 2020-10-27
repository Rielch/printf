#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct op - functions of formating text
 *
 * @c: argument character
 * @f: formating function
 */

typedef struct op
{
	char *c;
	int (*f)();
} printer;

int _printf(const char *format, ...);
int _printf2(const char *format, va_list args, printer *spec);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
int print_d(va_list args);
int print_b(va_list args);
int print_i2(int n);
int print_b2(unsigned int n);
int print_u(va_list args);
int print_u2(unsigned int n);
int print_o(va_list args);
int print_o2(int n);
int print_x(va_list args);
int print_x2(int n);
int print_X(va_list args);
int print_X2(int n);

#endif /* HOLBERTON_H */
