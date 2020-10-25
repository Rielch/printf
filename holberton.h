#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdlib.h>

/**
 * struct op - functions of formating text
 *
 * @c: argument character
 * @f: formating function
 */

typedef struct op
{
	char *c;
	void (*f)();
} printer;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
int print_d(va_list args);

#endif /* HOLBERTON_H */
