#include "main.h"

/**
 * _print_str - prints a string
 * @args: va_list for variadic arguments
 * Return: the number of characters printed
 */
int _print_str(va_list args)
{
	char *s;

	s = va_arg(args, char*);
	return (write(1, s, strlen(s)));
}
