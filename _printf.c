#include "main.h"

/**
 * _printf - for printing varied arguements
 * @format : first aguement
 * Return: returns printed.
 */
int _printf(const char *format, ...)
{
	int printed_char;

	va_list(_arguments);

	printed_char = 0;

	va_start(_arguments, format);

	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (format == '%')
		{
			format++;
			printed_char += _print_cases(format, _arguments);
		}
		else
		{
			printed_char += write(1, &(*format), 1);
			format++;
		}
	}

	va_end(_arguments);

	return (printed_char);
}
