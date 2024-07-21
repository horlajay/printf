#include "main.h"

/**
 * _printf - for printing characters to stdout
 * @format: the format string
 * Return: number of printed chars
 */

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUFFER_SIZE];
	int buf_index, num_p, i;

	if (format == NULL)
		return (-1);

	buf_index = 0;
	num_p = 0;
	i = 0;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				flush_buffer(buffer, &buf_index);
				va_end(args);
				return (-1);
			}
			switch (format[i])
			{
				case 'd':
				case 'i':
					num_p += handle_int(args, buffer, &buf_index);
					break;
				case 'b':
					num_p += handle_binary(args, buffer, &buf_index);
					break;
				case 'c':
					num_p += handle_char(args, buffer, &buf_index);
					break;
				case 's':
					num_p += handle_strings(args, buffer, &buf_index);
					break;
				case 'x':
					num_p += handle_hex(args, buffer, &buf_index);
					break;
				case 'X':
					num_p += handle_upper_hex(args, buffer, &buf_index);
					break;
				case 'S':
					num_p += handle_custom_string(args, buffer, &buf_index);
					break;
				case 'o':
					num_p += handle_octal(args, buffer, &buf_index);
					break;
				case 'u':
					num_p += handle_unsigned_int(args, buffer, &buf_index);
					break;
				case '%':
					num_p += handle_percent(buffer, &buf_index);
					break;
				default:
					if (buf_index + 2 > BUFFER_SIZE)
					{
						flush_buffer(buffer, &buf_index);
					}
					buffer[buf_index++] = '%';
					buffer[buf_index++] = format[i];
					num_p += 2;
					i++;
					break;
			}
		}
		else
		{
			if (buf_index + 1 > BUFFER_SIZE)
				flush_buffer(buffer, &buf_index);
			buffer[buf_index++] = format[i];
			num_p++;
		}
		i++;
	}

	flush_buffer(buffer, &buf_index);
	va_end(args);

	return (num_p);
}
