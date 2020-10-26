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
	int size = 0;
	printer spec[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
			};
	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	size = _printf2(format, args, spec);
	va_end(args);
	return (size);
}

/**
 * _printf2 - selects the function to format the text
 *
 * @format: text to be formated
 * @args: list of arguments
 * @spec: list of functions to format text
 * Return: size of printed text
 */

int _printf2(const char *format, va_list args, printer spec)
{
	int a = 0, b, size = 0;

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
	return (size);
}
