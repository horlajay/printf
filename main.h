#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#define BUFFER_SIZE 1024

void flush_buffer(char *buffer, int *buf_index);
void reverse_string(char *str, int len);
int handle_int(va_list args, char *buffer, int *buf_index);
int handle_binary(va_list args, char *buffer, int *buf_index);
int _printf(const char *format, ...);
int handle_hex(va_list args, char *buffer, int *buf_index);
int handle_strings(va_list args, char *buffer, int *buf_index);
int handle_char(va_list args, char *buffer, int *buf_index);
int handle_percent(char *buffer, int *buf_index);
int handle_pointer(va_list args, char *buffer, int *buf_index);
int handle_unsigned_int(va_list args, char *buffer, int *buf_index);
int handle_octal(va_list args, char *buffer, int *buf_index);
int handle_upper_hex(va_list args, char *buffer, int *buf_index);
int handle_custom_string(va_list args, char *buffer, int *buf_index);
#endif /*MAIN_H*/
