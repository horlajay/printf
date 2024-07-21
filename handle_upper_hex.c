#include "main.h"

/**
 * handle_upper_hex - for converting int to hexadicemal
 * @args: the int data
 * @buffer: the buffer
 * @buf_index: buffer index
 * Return: returns the number of printed chars
 */

int handle_upper_hex(va_list args, char *buffer, int *buf_index)
{
	unsigned int num;
	char temp_buffer[33];
	int i, len;
	const char *hex_digits;

	hex_digits = "0123456789ABCDEF";
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
		temp_buffer[i] = hex_digits[num % 16];
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
