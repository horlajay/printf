#include "main.h"

/**
 * handle_char - for handling the char specifier
 * @args: takes in the va_list argument
 * Return: returns the number printed characters
 */

int handle_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, sizeof(char));
	return (1);
}

/**
 * handle_strings - for handling strings
 * @args: for handling strings
 * Return: returns number of printed characters
 */

int handle_strings(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = "null";
	}
	write(1, s, strlen(s));

	return (strlen(s));
}

/**
 * handle_percent - for handling the percent
 * @args: the va_list element as the argument
 * Return: returns the number of the printed
 */

int handle_percent(void)
{
	char ch;

	ch = '%';
	write(1, &ch, sizeof(char));
	return (1);
}
