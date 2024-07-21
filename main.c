#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
    int len, len2;
    char str[1024];

    // Initialize the string with 1023 'a' characters and a null terminator
    for (int i = 0; i < 1023; i++)
    {
        str[i] = 'a';
    }
    str[1023] = '\0';

    len = _printf("%s", str);
    len2 = printf("%s", str);
    fflush(stdout);
    if (len != len2)
    {
        printf("Lengths differ.\n");
        fflush(stdout);
        return (1);
    }
    return (0);
}

