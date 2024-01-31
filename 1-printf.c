#include "main.h"

/**
 * _printf - for printing formatted output
 * @format - first arguement
 * return - the number of characters printed
 */

int _printf(const char *format, ...)
{
	int printed_char = 0;
	int sizeof_string;
	int a = 0;

	sizeof_string = strlen(format);
	va_list(args);
	va_start(args, format);

	if(format == NULL)
	{
		return (-1);
	}
	else
	{
		for (a = 0; a < sizeof_string; a++)
		{
			if (*format != '%')
			{
				write(1, format, 1);
				printed_char++;
				format++;
			}
			else
			{
				format++;
				{
					if (*format == 'c')
					{
						char c = va_arg(args , int);
						write(1, &c, 1);
						printed_char++;
						format++;
					}
					else if (*format == 's')
					{
						char *s = va_arg(args, char*);
						write(1, s, strlen(s));
						printed_char = printed_char + strlen(s);
						format++;
				
					}
					else if (*format == '%')
					{
						write(1, format, 1);
						printed_char++;
					}
				}
			}
		}
	}
	va_end(args);
	return (printed_char);
}






















