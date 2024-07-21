#include "main.h"

/**
 * handle_negative_int - for handling the negative part of the code
 * @str: the buffer
 * Return: void
 */

int handle_negative_int(char *str)
{
	char *min_int_str = "-2147483648";
	int len = 0;

	while (min_int_str[len])
	{
		str[len] = min_int_str[len];
		len++;
	}

	str[len] = '\0';
	write(1, str, len);
	return (len);
}

/**
 * reverse_string - reverses a string in place
 * @str: the string
 * @len: the length of the string
 * Return: void
 */

void reverse_string(char *str, int len)
{
	int start = 0;
	int end = len - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
