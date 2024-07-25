#include "main.h"

/**
 * my_itoa - for converting pointer value to hexadecimal
 * @args: the data
 * @buffer: the buffer
 * @buf_size: the buffer size
 * Return: returns void
 */

int handle_pointer(va_list args, char *buffer, int *buf_index)
{
	void *ptr;
	uintptr_t num;
	char temp_buffer[17];
	const char *null_str;
	int i, len digit;

	len = 0;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		null_str = "(nil)";
		while (*null_str)
		{
			if (*buf_index >= BUFFER_SIZE)
				flush_buffer(buffer, buf_index);
			buffer[(*buf_index)++] = *null_str++;
			len++;
		}
		return (len);
	}

	num = (uintptr_t)ptr;

	if (*buf_index + 2 >= BUFFER_SIZE)
		flush_buffer(buffer, buf_index);
	buffer[(*buf_index)++] = '0';
	buffer[(*buf_index)++] = 'x';
	len += 2;

	i = 0;

	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
			temp_buffer[i] = digit + '0';
		else
			temp_buffer[i] = digit - 10 + 'a';
		num /= 16;
		i++;
	}

	if (i == 0)
		temp_buffer[i++]  = '0';

	if (i > 0)
	{
		reverse_string(temp_buffer, i);
	}
	memcpy(buffer + *buf_index, temp_buffer, i);
	(*buf_index) += i;
	len += i;

	return (len);
}
