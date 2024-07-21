#include "main.h"

/*
 * handle_custom_string - for handling custom string
 * @args: the string
 * @buffer: the buffer
 * @buf_index: the buffer index
 * Return: returns the number printed chars
 */

int handle_custom_string(va_list args, char *buffer, int *buf_index)
{
	char *s;
	int i, num_p = 0;
	unsigned char c;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		c = (unsigned char)s[i];
		if (c < 32 || c >= 127)
		{
			if (*buf_index + 4 >= BUFFER_SIZE)
				flush_buffer(buffer, buf_index);

			buffer[*buf_index] = '\\';
			buffer[*buf_index + 1] = 'x';
			buffer[*buf_index + 2] = "0123456789ABCDEF"[c / 16];
			buffer[*buf_index + 3] = "0123456789ABCDEF"[c % 16];
			*buf_index += 4;
			num_p += 4;
		}
		else
		{
			if (*buf_index + 1 >= BUFFER_SIZE)
				flush_buffer(buffer, buf_index);

			buffer[*buf_index] = c;
			(*buf_index)++;

			num_p++;
		}
	}

	return (num_p);
}
