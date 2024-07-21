#include "main.h"

/**
 * reverse_string - for reversing a string
 * @str: the string to be reversed
 * @len: the length of the string
 * Return: returns the void
 */

void reverse_string(char *str, int len)
{
	int start, end;
	char temp;

	start = 0;
	end = len - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * flush_buffer - for printing and deleting the data in a buffer
 * @buffer: the buffer
 * @buf_index: the index of the buffer
 * Return: returns void
 */

void flush_buffer(char *buffer, int *buf_index)
{
	if (*buf_index > 0)
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}
}
