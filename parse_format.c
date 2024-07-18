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
			if (format[i + 1] == '\0')
			{
				return (-1);
			}
			num_p = _switch(format, args, &i, num_p);
		}
		else
		{
			write(1, &format[i], sizeof(char));
			num_p++;
		}
		i++;
	}

	return (num_p);
}
