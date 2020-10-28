#include "holberton.h"

/**
 * print_S - prints a string with non printable characters in hexadecimal
 *
 * @args: argument given to the function
 * @buff: buffer
 * @ch: buffer position
 * Return: ammount of characters writed
 */

int print_S(va_list args, char *buff, int ch)
{
	int a, size = 0;
	int c;
	char *str = va_arg(args, char *);

	for (a = 0; str[a] != '\0'; a++)
	{
		if (str[a] < 32 || str[a] >= 127)
		{
			buff[ch + size] = '\\';
			buff[ch + size + 1] = 'x';
			size += 2;
			c = str[a];
			size += print_XS(c, buff, (ch + size));
		}
		else
		{
			buff[ch + size] = str[a];
			size++;
		}
	}
	return (size);
}
