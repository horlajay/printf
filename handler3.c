#include "main.h"

/**
 * handle_binary - for converting an unsigned int to binary
 * @args: the arg argument or the unsigned int
 * Return: returns the number of printed chars
 */

int handle_binary(va_list args)
{
	unsigned long int num;
	char buffer[33];
	int i, len;

	i = 0;
	len = 0;
	num = va_arg(args, unsigned long int);

	if (num == 0)
	{
		buffer[i] = '0';
		buffer[i++] = '\0';
		write(1, buffer, 1);
		return (1);
	}

	while (num > 0)
	{
		buffer[i] = (num % 2) + '0';
		num = num / 2;
		i++;
	}

	buffer[i] = '\0';

	reverse_string(buffer, i);
	len = strlen(buffer);
	write(1, buffer, len);

	return (len);
}
