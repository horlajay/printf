#include "main.h"
/**
 * _printf - for printing formatted output
 * @format : first argument
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_char = 0;
	int sizeof_string = strlen(format);
	int a;
	va_list args;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}
	else
	{
		for (a = 0; a < sizeof_string; a++)
		{
			if (*format != '%')
			{
				printed_char += _write_char(*format);
				format++; }
			else
			{
				format++;
				if (*format == 'c')
					printed_char += _print_char(args);
				else if (*format == 's')
					printed_char += _print_str(args);
				else if (*format == '%')
					printed_char += _write_char('%'); }
			format++; }
	}
	va_end(args);
	return (printed_char);
}
