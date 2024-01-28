#include "main.h"
/**
 * _printf: it is a function that prints formatted output.
 * @format: it is a pointer to a constant string.
 *
 * Return:the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int printed_char = 0;

	va_list(args_lists);

	if (format == NULL)
		return (-1);

	va_start(args_lists, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_char++;
		}
		else
		{
			format++;
			break;
			if (*format == 'c')
			{
				char c = va_arg(args_lists, int);

				write(1, &c, 1);
				printed_char++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				printed_char++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args_lists, char *);

				write(1, &s, strlen(s));
				printed_char += strlen;
			}
		}
		format++;
	}
		va_end(args_lists);
		return (printed_char);


}
