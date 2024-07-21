#include "main.h"

/**
 * handle_binary - for printing numbers in binary
 * @args: the int data
 * @buffer: the buffer
 * @buf_index: the buffer index
 * Return: returns the size of the chars
 */

int handle_binary(va_list args, char *buffer, int *buf_index)
{
	int i, len;
	unsigned int num;
	char temp_buf[33];

	i = 0;
	len = 0;
	num = va_arg(args, unsigned int);

	if (num == 0)
	{
		temp_buf[i] = '0';
		temp_buf[i + 1] = '\0';
		i++;
	}

	while (num > 0)
	{
		temp_buf[i] = (num % 2) + '0';
		num = num / 2;
		i++;
	}

	temp_buf[i] = '\0';
	reverse_string(temp_buf, i);

	len = i;
	if ((*buf_index + len) > BUFFER_SIZE)
	{
		flush_buffer(buffer, buf_index);
	}

	memcpy(buffer + *buf_index, temp_buf, len);
	*buf_index += len;

	return (len);
}
