#include "holberton.h"

/**
 * _printf - prints formated text
 *
 * @format: text to be formated
 * Return: Lenght of the text
 */

int _printf(const char *format, ...)
{
	va_list args;
	int a = 0, b, size = 0;
	printer spec[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
			};
	va_start(args, format);
	while (format && format[a])
	{
		if (format[a] == '%')
		{
			b = 0;
			while (spec[b].c != NULL)
			{
				if (format[a + 1] == '%')
				{
					write(1, &format[a], 1);
					size++;
					a++;
					break;
				}
				else if (spec[b].c[0] == format[a + 1])
				{
					size += spec[b].f(args);
					a++;
					break;
				}
				b++;
			}
		}
		else
		{
			write(1, &format[a], 1);
			size++;
		}
		a++;
	}
	va_end(args);
	return (size);
}
