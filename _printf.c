#include "main.h"

/**
 * _printf - for printing formatted output
 * @format : format string
 * Return: the number of characters printed (excluding null terminator
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int printed_char = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			printed_char += _write_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
				printed_char += _print_char(args);
			else if (*format == 's')
				printed_char += _print_str(args);
			else if (*format == '%')
				printed_char += _write_char('%');
		}
		format++;
	}

	va_end(args);
	return (printed_char);
}
