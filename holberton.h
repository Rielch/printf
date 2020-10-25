#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>

typedef struct op
{
	char *c;
	void (*f)();
} printer;

int _printf(const char *format, ...);

#endif /* HOLBERTON_H */
