#include "holberton.h"

/**
 * print_u - prints an unsigned decimal integer
 *
 * @args: argument given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_u(va_list args, char *buff, int ch)
{
	unsigned int n = va_arg(args, int);
	int size = 0;

	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}
	ch = ch + size;
	size += print_u2(n, buff, ch);
	return (size);
}

/**
 * print_u2 - prints an unsigned decimal integer
 *
 * @n: number to be printed
 * @buff: buffer
 * @ch: character count for buffer
 * Return: Ammount of characters writed
 */

int print_u2(unsigned int n, char *buff, int ch)
{
	int size = 0;
	unsigned int a;

	if (n > 0)
	{
		a = n % 10;
		size = print_u2((n / 10), buff, ch);
		buff[ch + size] = a + '0';
		size++;
	}
	return (size);
}

/**
 * print_o - prints an integer in octal
 *
 * @args: argumen given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_o(va_list args, char *buff, int ch)
{
	int size = 0;
	unsigned int n = va_arg(args, int);

	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}
	ch = ch + size;
	size += print_o2(n, buff, ch);
	return (size);
}

/**
 * print_o2 - prints a number in octal
 *
 * @n: number to be printed
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_o2(unsigned int n, char *buff, int ch)
{
	unsigned int a;
	int size = 0;

	if (n != 0)
	{
		a = n % 8;
		size = print_o2((n / 8), buff, ch);
		buff[ch + size] = a + '0';
		size++;
	}
	return (size);
}
