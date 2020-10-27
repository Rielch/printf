#include "holberton.h"

/**
 * print_x - prints a number in hexadecimal
 *
 * @args: argument given to the function
 * Return: ammount of characters writed
 */

int print_x(va_list args)
{
	int n, size = 0;
	char c = '-';

	n = va_arg(args, int);
	if (n == 0)
	{
		c = n + '0';
		write(1, &c, 1);
		size++;
	}
	if (n < 0)
	{
		write(1, &c, 1);
		size++;
	}
	size += print_x2(n);
	return (size);
}

/**
 * print_x2 - prints a number in hexadecimal
 *
 * @n: number to print in hexadecimal
 * Return: ammount of characters writed
 */

int print_x2(int n)
{
	int size = 0, a;
	char c;

	if (n != 0)
	{
		a = n % 16;
		size = print_x2(n / 16);
		if (a < 0)
		{
			a = a * -1;
		}
		if (a / 10 != 0)
		{
			a = a % 10;
			c = a + 'a';
			write(1, &c, 1);
			size++;
		}
		else
		{
			c = a + '0';
			write(1, &c, 1);
			size++;
		}
	}
	return (size);
}

/**
 * print_X - prints an integer in hexadecimal in uppercase
 *
 * @args: argumen given to the function
 * Return: ammount of characters writen
 */

int print_X(va_list args)
{
	int size = 0, n;
	char c = '-';

	n = va_arg(args, int);
	if (n == 0)
	{
		c = n + '0';
		write(1, &c, 1);
		size++;
	}
	if (n < 0)
	{
		write(1, &c, 1);
		size++;
	}
	size += print_X2(n);
	return (size);
}

/**
 * print_X2 - prints a number in hexadecimal in uppercase
 *
 * @n: number to print
 * Return: ammount of characters writed
 */

int print_X2(int n)
{
	int a, size = 0;
	char c;

	if (n != 0)
	{
		a = n % 16;
		size = print_X2(n / 16);
		if (a < 0)
		{
			a = a * -1;
		}
		if (a / 10 != 0)
		{
			a = a % 10;
			c = a + 'A';
			write(1, &c, 1);
			size++;
		}
		else
		{
			c = a + '0';
			write(1, &c, 1);
			size++;
		}
	}
	return (size);
}
