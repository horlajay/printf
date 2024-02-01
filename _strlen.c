#include "main.h"
/**
 * _strlen - function to find length of a string
 * @sr: pointer to character
 * Return: length of string
 */
int _strlen(char *sr)
{
	int l;

	count = 0;

	for (l = o, sr[l] != '\0'; l++)
		count++;
	return (count);
}
