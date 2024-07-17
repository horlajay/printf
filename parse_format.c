#include "main.h"

/**
 * parse_format - for parsing the string
 * @format : the string
 * @args: the args argument
 * Return: returns int
 */

int parse_format(const char *format, va_list args)
{
	int i = 0;
	int num_p = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					num_p += handle_char(args);
					i++;
					break;
				case 's':
					num_p += handle_strings(args);
					i++;
					break;
				case '%':
					num_p += handle_percent();
					i++;
					break;
				default:
					break; } }
		else
		{
			write(1, &format[i], sizeof(char));
			num_p++; }
		i++; }
	return (num_p);
}
