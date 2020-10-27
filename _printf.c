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
	char *buff = malloc(1024 * sizeof(char));
	printer spec[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{NULL, NULL}
			};
	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	size = _printf2(format, args, spec, buff);
	write(1, buff, size);
	free(buff);
	va_end(args);
	return (size);
}

/**
 * _printf2 - selects the function to format the text
 *
 * @format: text to be formated
 * @args: list of arguments
 * @spec: list of functions to format text
 * @buff: buffer
 * Return: size of printed text
 */

int _printf2(const char *format, va_list args, printer *spec, char *buff)
{
	int a = 0, b, size = 0, test = 0;

	while (format && format[a])
	{
		if (format[a] == '%')
		{
			b = 0;
			while (spec[b].c != NULL)
			{
				if (format[a + 1] == '%')
				{
					buff[size] = format[a];
					size++;
					a++;
					test = 1;
					break;
				}
				else if (spec[b].c[0] == format[a + 1])
				{
					size += spec[b].f(args, buff, size);
					a++;
					test = 1;
					break;
				}
				b++;
			}
			if (test == 0)
			{
				buff[size] = format[a];
				size++;
			}
		}
		else
		{
			buff[size] = format[a];
			size++;
		}
		a++;
	}
	return (size);
}
