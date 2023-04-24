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
    const char *p = format;

    if (format == NULL)
        return (-1);

    va_start(args, format);

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

                case 's':
                    count += _puts(va_arg(args, char *));
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

    va_end(args);

    return (count);
}
