#include "holberton.h"

/**
 * print_u - prints an unsigned decimal integer
 *
 * @args: argument given to the function
 * Return: ammount of characters writed
 */

int print_u(va_list args)
{
	unsigned int n = va_arg(args, int);
	int size = 0;
	char c;

	if (n == 0)
	{
		c = n + '0';
		write(1, &c, 1);
		size++;
	}
	size += print_u2(n);
	return (size);
}

/**
 * print_u2 - prints an unsigned decimal integer
 *
 * @n: number to be printed
 * Return: Ammount of characters writed
 */

int print_u2(unsigned int n)
{
	int size = 0;
	char c;
	unsigned int a;

	if (n > 0)
	{
		a = n % 10;
		size = print_u2(n / 10);
		c = a + '0';
		write(1, &c, 1);
		size++;
	}
	return (size);
}

/**
 * print_o - prints an integer in octal
 *
 * @args: argumen given to the function
 * Return: ammount of characters writed
 */

int print_o(va_list args)
{
	int size = 0;
	unsigned int n = va_arg(args, int);
	char c;

	if (n == 0)
	{
		c = n + '0';
		write(1, &c, 1);
		size++;
	}
	size += print_o2(n);
	return (size);
}

/**
 * print_o2 - prints a number in octal
 *
 * @n: number to be printed
 * Return: ammount of characters writed
 */

int print_o2(unsigned int n)
{
	unsigned int a;
	int size = 0;
	char c;

	if (n != 0)
	{
		a = n % 8;
		size = print_o2(n / 8);
		c = a + '0';
		write(1, &c, 1);
		size++;
	}
	return (size);
}
