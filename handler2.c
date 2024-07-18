#include "main.h"

/**
 * handle_int - for handling int data in printf
 * @args: the args list as the argument
 * Return: returns the number printed characters
 */

int handle_int(va_list args)
{
	int len, num, i, is_negative, start;
	char buffer[20], temp;

	start = 0;
	len = 0;
	i = 0;
	is_negative = 0;
	num = va_arg(args, int);
	if (num == 0)
	{
		buffer[i] = '0';
		buffer[i + 1] = '\0';
		write(1, buffer, 1);
		return (1); }
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
	i--;
	while (start < i)
	{
		temp = buffer[start];
		buffer[start] = buffer[i];
		buffer[i] = temp;
		start++;
		i--; }
	len = strlen(buffer);
	write(1, buffer, len);
	return (len);
}
