#include "main.h"

/**
 * _write_char - writes a character to stdout
 * @c: the character to print
 * Return: the number of characters printed (always 1)
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
