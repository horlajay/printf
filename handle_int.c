#include "main.h"

/**
 * handle_int - for handling int arguments
 * @args: the int argument
 * @buffer: the string
 * @buf_index: the index of the buffer
 * Return: returns the number of chars printed
 */

int handle_int(va_list args, char *buffer, int *buf_index)
{
	int num, i, len, is_negative;
	char temp_buffer[20], *min_int_str;

	min_int_str = "-2147483648";
	i = 0;
	len = 0;
	is_negative = 0;
	num = va_arg(args, int);

	if (num == 0)
	{
		buffer[*buf_index] = '0';
		(*buf_index)++;
		if (*buf_index >= BUFFER_SIZE)
			flush_buffer(buffer, buf_index);
		return (1);
	}

	if (num == INT_MIN)
	{
		for (i = 0; min_int_str[i] != '\0'; i++)
		{
			buffer[*buf_index] = min_int_str[i];
			(*buf_index)++;
			if (*buf_index >= BUFFER_SIZE)
				flush_buffer(buffer, buf_index);
		}
		return (i);
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num > 0)
	{
		temp_buffer[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	if (is_negative)
	{
		temp_buffer[i] = '-';
		i++;
	}

	temp_buffer[i] = '\0';

	reverse_string(temp_buffer, i);

	len = i;

	if (*buf_index + len > BUFFER_SIZE)
	{
		flush_buffer(buffer, buf_index);
	}

	memcpy(buffer + *buf_index, temp_buffer, len);
	*buf_index += len;

	return (len);
}
