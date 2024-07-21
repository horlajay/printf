#include "main.h"
/**
 * handle_char - for handling teh char specifier
 * @args: the char
 * @buffer: the buffer
 * @buf_index: the buffer size
 * Return: returns the printed chars
 */

int handle_char(va_list args, char *buffer, int *buf_index)
{
	char c;

	c = va_arg(args, int);
	buffer[*buf_index] = c;
	(*buf_index)++;
	if (*buf_index >= BUFFER_SIZE)
	{
		flush_buffer(buffer, buf_index);
	}
	return (1);
}


/**
 * handle_strings - for handling the string input
 * @args: the string
 * @buffer: the buffer
 * @buf_index: the buffer index
 * Return: returns the printed chars
 */

int handle_strings(va_list args, char *buffer, int *buf_index)
{
	char *s;
	int i, len;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";
	len = strlen(s);

	for (i = 0; i < len; i++)
	{
		buffer[*buf_index] = s[i];
		(*buf_index)++;
		if (*buf_index >= BUFFER_SIZE)
			flush_buffer(buffer, buf_index);
	}

	return (i);
}

/**
 * handle_percent - for handling the percent
 * @buffer: the buffer
 * @buf_index: the buffer index
 * Return: returns the number of printed chars
 */

int handle_percent(char *buffer, int *buf_index)
{
	char ch;

	ch = '%';
	buffer[*buf_index] = ch;
	(*buf_index)++;

	if (*buf_index >= BUFFER_SIZE)
		flush_buffer(buffer, buf_index);
	return (1);
}
