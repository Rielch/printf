#include "holberton.h"

/**
 * print_i - prints an integer in decimal
 *
 * @args: arguments given to the function
 * Return: Ammount of characters writed
 */

int print_i(va_list args)
{
	int n = va_arg(args, int);
	int size = 0;
	char min = '-';
	if (n < 0)
	{
		write(1, &min, 1);
		n = n * -1;
		size++;
	}
	size += print_i2(n);
	return (size);
}


int print_i2(int n)
{
	char c;
	int size = 0, a;

	if (n > 0)
	{
		a = n % 10;
		size = print_i2(n / 10);
		c = a + '0';
		write(1, &c, 1);
		size++;
	}
	return (size);
}

/**
 * print_d - prints a decimal
 *
 * @args: argument given to the function
 * Return: Ammount of characters writed
 */

int print_d(va_list args)
{
        int n = va_arg(args, int);
        int size = 0;
        char min = '-';
        if (n <= 2147483647 && n >= -2147483648)
        {
                if (n < 0)
                {
                        write(1, &min, 1);
                        n = n * -1;
                        size++;
                }
                size += print_i2(n);
                return (size);
        }
        else
        {
                return (0);
        }
}
