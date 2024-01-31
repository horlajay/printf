#include "main.h"

/**
 * _print_char - prints a character
 * @args: va_list for variadic arguments
 * Return: the number of characters printed
 */
int _print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (_write_char(c));
}
