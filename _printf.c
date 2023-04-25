#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _print_helper - prints output to stdout according to a format
 * @p: character string containing zero or more directives
 * @args: args to be printed
 * Return: the number of characters printed
 */
int _print_helper(const char *p, va_list args)
{
int n, count = 0;
char buf[12];

while (*p != '\0')
{
	if (*p == '%')
	{
		p++;
		switch (*p)
		{
		case 'c':
			count += _putchar(va_arg(args, int));
		break;
		case 'b':
			count += print_binary(args);
		break;
		case 's':
			count += _puts(va_arg(args, char *));
		break;
		case 'd':
		case 'i':
			n = va_arg(args, int);
			sprintf(buf, "%d", n);
			count += _puts(buf);
		break;
		case '%':
			count += _putchar('%');
		break;
		default:
			count += _putchar('%');
			count += _putchar(*p);
		break;
		}
	}
	else
	{
		count += _putchar(*p);
	}
	p++;
}
	return (count);
}

/**
 * _printf - prints output to stdout according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format || (format[0] == '%' && !format[1]))
	return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);
	va_start(args, format);
	count = _print_helper(format, args);
	va_end(args);
	return (count);
}
