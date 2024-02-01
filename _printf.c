#include "main.h"
/**
 * _printf - for printing varied arguements
 * @format : first aguement
 * Return: returns printed.
 */
int _printf(const char *format, ...)
{
	va_list(args);
	int printed_char;
	int size_of_string;
	char c;
	char *s;

	size_of_string = strlen(format);
	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (int a = 0; a < size_of_string; a++)
	{
		if (*format == '\0')
			break;
		if (*format != '%')
		{
			write(1, format, 1);
			printed_char++;
			format++; }
		else
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
				write(1, s, strlen(s));
				printed_char = printed_char + strlen(s);
				format++; }
			else if (*format == '%')
			{
				write(1, format, 1);
				printed_char++; } } }
	va_end(args);
	return (printed_char); }
