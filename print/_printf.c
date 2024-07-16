#include "main.h"

/**
 * _printf - for printing or functioning like printf
 * @format: the string to be formated and printed
 * Return: returns the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int num_p;

	if (format == NULL)
		return (-1);

	num_p = 0;
	va_start(args, format);
	num_p += parse_format(format, args);
	va_end(args);

	return (num_p);
}
