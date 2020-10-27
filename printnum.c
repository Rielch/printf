#include "holberton.h"

/**
 * print_i - prints an integer in decimal
 *
 * @args: arguments given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: Ammount of characters written
 */

int print_i(va_list args, char *buff, int ch)
{
	int n = va_arg(args, int);
	int size = 0;

	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}

	if (n < 0)
	{
		buff[ch + size] = '-';
		size++;
	}
	ch = ch + size;
	size += print_i2(n, buff, ch);
	return (size);
}

/**
 * print_i2 - prints a number
 *
 * @n: number to print
 * @buff: buffer
 * @ch: character count for buffer
 * Return: Size in characters of the number
 */

int print_i2(const int n, char *buff, int ch)
{
	int size = 0, a;

	if (n != 0)
	{
		a = n % 10;
		size = print_i2((n / 10), buff, ch);
		if (a < 0)
		{
			a = a * -1;
		}
		buff[size + ch] = a + '0';
		size++;
	}
	return (size);
}

/**
 * print_d - prints a decimal
 *
 * @args: argument given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: Ammount of characters writed
 */

int print_d(va_list args, char *buff, int ch)
{
	int n = va_arg(args, int);
	int size = 0;

	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}
	if (n < 0)
	{
		buff[ch + size] = '-';
		size++;
	}
	ch = ch + size;
	size += print_i2(n, buff, ch);
	return (size);
}

/**
 * print_b - prints an unsigned int as binary
 *
 * @args: argument given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_b(va_list args, char *buff, int ch)
{

	unsigned int n = va_arg(args, int);
	int size = 0;

	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}
	ch = ch + size;
	size += print_b2(n, buff, ch);
	return (size);
}

/**
 * print_b2 - prints as binary
 *
 * @n: number to print
 * @buff: buffer
 * @ch: character count for buffer
 * Return: Ammount of characters writed
 */

int print_b2(unsigned int n, char *buff, int ch)
{
	int size = 0;
	unsigned int a;

	if (n > 0)
	{
		a = n % 2;
		size = print_b2((n / 2), buff, ch);
		buff[ch + size] = a + '0';
		size++;
	}
	return (size);
}
