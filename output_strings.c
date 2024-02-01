#include "main.h"
/**
 * output_strings - function to print a string
 * @_arguments: Arguments passed
 * Return: Printed String
 */
int output_strings(va_list _arguments)
{
	char *st;

	int j;

	int len;

	st = va_arg(_arguments, char *);
	if (st == NULL)
	{
		st = "(null)";
		len = _strlen(st);
		for (j = 0; j < len; j++)
			_put_char(st[j]);
		return (len);
	}
	else
	{
		len = _strlen(st);
		for (j = 0; j < len; j++)
			_put_char(st[j]);
		return (len);
	}
}
