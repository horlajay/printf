#include "main.h"

/**
 * handle_octal - for printing int values in octal
 * @args: the int data
 * @buffer: the buffer
 * @buf_index: the buffer index
 * Return: returns the number of printed chars
 */

int handle_octal(va_list args, char *buffer, int *buf_index)
{
	int i, len;
	unsigned int num;
	char temp_buffer[33];

	i = 0;
	len = 0;
	num = va_arg(args, unsigned int);

	if (num == 0)
	{
		buffer[*buf_index] = '0';
		(*buf_index)++;
		if (*buf_index >= BUFFER_SIZE)
			flush_buffer(buffer, buf_index);
		return (1);
	}

	while (num > 0)
	{
		temp_buffer[i] = (num % 8) + '0';
		num = num / 8;
		i++;
	}

	temp_buffer[i] = '\0';
	reverse_string(temp_buffer, i);

	len = i;
	if ((*buf_index + len) >= BUFFER_SIZE)
		flush_buffer(buffer, buf_index);
	memcpy(buffer + *buf_index, temp_buffer, len);
	(*buf_index) += len;

	return (len);
}
