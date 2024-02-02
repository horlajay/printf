#include "main.h"
/**
 * _printf - for printing varied arguements
 * @format : first aguement
 * Return: returns printed.
 */
int _printf(const char *format, ...)
{
	va_list(args);
	int printed_char, size_of_string, a;
	char c, *s;

	size_of_string = sizeof(format);
	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (a = 0; a < size_of_string; a++)
	{
		if (*format == '\0')
			break;
		if (*format != '%')
		{
			write(1, format, 1);
			printed_char++;
			format++; }
		else if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				printed_char++;
				format++; }
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				write(1, s, sizeof(s));
				printed_char = printed_char + sizeof(s);
				format++; }
			else if (*format == '%')
			{
				write(1, format, 1);
				printed_char++;
				format++; } } }
	va_end(args);
	return (printed_char); }
