#include "holberton.h"

/**
 * print_c - prints a single char
 * @args: arguments received from _printf
 * @buff: buffer
 * @ch: character count for buffer
 * Return: numbers of chars
 */
int print_c(va_list args, char *buff, int ch)
{
	char c = va_arg(args, int);

	buff[ch] = c;
	return (1);
}


/**
 * print_s - prints a string
 * @args: arguments received from _printf
 * @buff: buffer
 * @ch: character count for buffer
 * Return: number of chars
 */
int print_s(va_list args, char *buff, int ch)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		buff[ch + i] = str[i];
	}
	return (i);
}
