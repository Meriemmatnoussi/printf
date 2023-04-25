#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int _print_helper(const char *p, va_list args);
int print_binary(va_list list);
char* rev_string(char* s);
unsigned int base_len(unsigned int num, int base);

#endif
