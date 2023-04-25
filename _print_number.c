#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _print_number - prints an integer to stdout
 * @n: integer to print
 *
 * Return: the number of characters printed
 */
int _print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		count += _print_number(n / 10);
	}
	count += _putchar((n % 10) + '0');

	return count;
}
