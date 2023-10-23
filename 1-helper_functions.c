#include "main.h"

/**
 * _putchar - print a character to standard output
 * @c: Character to be printed
 * Return: total number of characters printed
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_int - prints an integer
 * @args: list of integers to be printed
 * Return: total number of numbers
 */

int print_int(va_list args)
{
	long num = va_arg(args, long);
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		int reverse_num = 0;

		while (num > 0)
		{
			reverse_num = reverse_num * 10 + num % 10;
			num /= 10;
		}
		while (reverse_num > 0)
		{
			_putchar(reverse_num % 10 + '0');
			count++;
			reverse_num /= 10;
		}
	}
	return (count);
}
