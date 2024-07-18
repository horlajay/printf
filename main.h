#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_strings(va_list args);
int handle_percent(void);
int parse_format(const char *format, va_list args);
int _switch(const char *format, va_list args, int *i, int num_p);
int handle_int(va_list args);
int handle_negative_int(char *str);
void reverse_string(char *str, int len);
#endif
