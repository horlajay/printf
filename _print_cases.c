#include "main.h"
/**
 * _print_cases - to print and compare cases
 * @format: pointer to the constant character
 * @_arguments: arguments passed to the function
 * Return: printed character
 */
int _print_cases(const char *format, va_list _arguments)
{
	int printed_char = 0;

	if (*format == 'c')
	{
		printed_char += _put_char(va_arg(_argumets, int));
	}
	else if (*format == 's')
	{
		printed_char += output_strings(va_arg(_arguments, char *));
	}
	else if (*format == '%')
	{
		printed_char += _put_char('%');
	}
	else if (*format == '\0')
	{
		return (-1);
	}
	else
	{
		printed_char += write(1, &(*format), 1);
	}
	return (printed_char);
