#include "main.h"

/**
  * _printf - Print like a printf
  * @format: Args to the function
  *
  * Return: A format string to output
  */


int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			while (*(format + 1) == ' ')
				format++;
			format++;
			if (*format == '\0' || *format == ' ')
				return (-1);
			if (*format == 'c')
				count += handle_c(args);
			else if (*format == 's')
				count += handle_s(args);
			else if (*format == '%')
				count += print_char('%');
			else if (*format == 'd' || *format == 'i')
				count += print_int(args);
			else
			{
				format--;
				count += print_char(*format);
			}
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}
