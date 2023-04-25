#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int _print_number(int n);
int _handle_format_specifier(const char **format, va_list args);

#endif
