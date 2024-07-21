#include "main.h"

/**
 * handle_hex - for converting an unsigned int to hex
 * @args: the int data
 * @buffer: the buffer
 * @buf_index: the buffer index
 * Return: the number of printed chars
 */

int handle_hex(va_list args, char *buffer, int *buf_index)
{
	unsigned int num;
	int i, len, remainder;
	char temp_buffer[33];

	remainder = 0;
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
		remainder = num % 16;
		if (remainder < 10)
			temp_buffer[i] = remainder + '0';
		else
			temp_buffer[i] = (remainder - 10) + 'a';
		num = num / 16;
		i++;
	}
	temp_buffer[i] = '\0';

	reverse_string(temp_buffer, i);
	len = i;

	if (*buf_index + len >= BUFFER_SIZE)
		flush_buffer(buffer, buf_index);
	memcpy(buffer + *buf_index, temp_buffer, len);
	(*buf_index) += len;
	return (len);
}
