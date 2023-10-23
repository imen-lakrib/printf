#include "main.h"

/**
  * print_char - Function to print a character
  * @c: Args
  *
  * Return: 1 for each char called
 */

int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
  * print_string - stdout the string passed to it
  * @str: Pointer to the string
  *
  * Return: Number of char
  */

int print_string(char *str)
{
	int count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		count = strlen(str);
		write(1, str, count);
		return (count);
	}
}

/**
  * handle_s - stdout handling the test of s
  * @args: Va_list args
  *
  * Return: 0 Success
  */

int handle_s(va_list args)
{
	char *str;

	str = va_arg(args, char *);

	if (str == NULL)
		return (print_string("(null)"));
	else
		return (print_string(str));
}

/**
  * handle_c - stdout handling c
  * @args: Variadic function args
  *
  * Return: 0 Success
  */

int handle_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (print_char(c));
}
