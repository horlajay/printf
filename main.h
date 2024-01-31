#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#include "_printf.c"

int _put_char(char c);
int _printf(const char *format, ...);
int _print_cases(const char *format, va_list _arguments);

#endif
