#include "holberton.h"

/**
 * print_x - prints a number in hexadecimal
 *
 * @args: argument given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_x(va_list args, char *buff, int ch)
{
	unsigned int n, size = 0;

	n = va_arg(args, int);
	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}
	ch = ch + size;
	size += print_x2(n, buff, ch);
	return (size);
}

/**
 * print_x2 - prints a number in hexadecimal
 *
 * @n: number to print in hexadecimal
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_x2(unsigned int n, char *buff, int ch)
{
	int size = 0;
	unsigned int a;

	if (n != 0)
	{
		a = n % 16;
		size = print_x2((n / 16), buff, ch);
		if (a / 10 != 0)
		{
			a = a % 10;
			buff[ch + size] = a + 'a';
			size++;
		}
		else
		{
			buff[ch + size] = a + '0';
			size++;
		}
	}
	return (size);
}

/**
 * print_X - prints an integer in hexadecimal in uppercase
 *
 * @args: argumen given to the function
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writen
 */

int print_X(va_list args, char *buff, int ch)
{
	int size = 0;
	unsigned int n;

	n = va_arg(args, int);
	if (n == 0)
	{
		buff[ch + size] = n + '0';
		size++;
	}
	ch = ch + size;
	size += print_X2(n, buff, ch);
	return (size);
}

/**
 * print_X2 - prints a number in hexadecimal in uppercase
 *
 * @n: number to print
 * @buff: buffer
 * @ch: character count for buffer
 * Return: ammount of characters writed
 */

int print_X2(unsigned int n, char *buff, int ch)
{
	unsigned int a;
	int size = 0;

	if (n != 0)
	{
		a = n % 16;
		size = print_X2((n / 16), buff, ch);
		if (a / 10 != 0)
		{
			a = a % 10;
			buff[ch + size] = a + 'A';
			size++;
		}
		else
		{
			buff[ch + size] = a + '0';
			size++;
		}
	}
	return (size);
}
