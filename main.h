#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#include "_write.c"
#include "_printf.c"
#include "_print_char.c"
#include "_print_str.c"

int _printf(const char *format, ...);
int _write_char(char c);
int _print_char(va_list args);
int _print_str(va_list args);

#endif
