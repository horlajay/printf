#include "main.h"

/**
 * handle_int - for handling int data in printf
 * @args: the args list as the argument
 * Return: returns the number printed characters
 */

int handle_int(va_list args)
{
	int len, num, i, is_negative;
	char buffer[25];

	len = 0;
	i = 0;
	is_negative = 0;
	num = va_arg(args, int);
	if (num == 0)
	{
		buffer[i] = '0';
		buffer[i + 1] = '\0';
		len = strlen(buffer);
		write(1, buffer, len);
		return (len);
	}
	else if (num == INT_MIN)
		return (handle_negative_int(buffer));
	if (num < 0)
	{
		is_negative = 1;
		num = -num; }
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		num = num / 10;
		i++; }
	if (is_negative)
	{
		buffer[i] = '-';
		i++; }
	buffer[i] = '\0';

	reverse_string(buffer, i);
	len = strlen(buffer);
	write(1, buffer, len);
	return (len);
}
