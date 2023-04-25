#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

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

	while (*format != '\0')
	{
		if (*format == '%')
		{
		count += _handle_format_specifier(&format, args);
		}
		else
		{
		count += _putchar(*format);
		format++;
		}
	}

	va_end(args);
	return (count);
}

/**
 * _handle_format_specifier - handles format specifier and prints corresponding
 * argument(s)
 * @format: pointer to format string
 * @args: argument list
 *
 * Return: the number of characters printed
 */
int _handle_format_specifier(const char **format, va_list args)
{
	int count = 0;

	switch (*++(*format))
	{
		case 'c':
		count += _putchar(va_arg(args, int));
		break;

		case 's':
		count += _puts(va_arg(args, char *));
		break;

		case '%':
		count += _putchar('%');
		break;

		case 'd':
		case 'i':
		count += _print_number(va_arg(args, int));
		break;

		default:
		count += _putchar('%');
		count += _putchar(*(*format - 1));
		break;
	}

	return (count);
}
