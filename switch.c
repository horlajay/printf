#include "main.h"

/**
 * _switch - for using the switch syntax to parse the format string
 * @format: the string
 * @args: the variable argument list
 * @i: the int value or iterator
 * @num_p: the number of characters printed
 * Return: returns an int
 */

int _switch(const char *format, va_list args, int *i, int num_p)
{
	switch (format[*i + 1])
	{
		case 'c':
			num_p += handle_char(args);
			(*i)++;
			break;
		case 's':
			num_p += handle_strings(args);
			(*i)++;
			break;
		case 'd':
		case 'i':
			num_p += handle_int(args);
			(*i)++;
			break;
		case '%':
			num_p += handle_percent();
			(*i)++;
			break;
		default:
			write(1, "%", 1);
			write(1, &format[*i + 1], 1);
			num_p += 2;
			(*i)++;
			break;
	}
	return (num_p);
}
