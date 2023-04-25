#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * rev_string - reverses a given string in place
 * @s: character pointer to string to be reversed
 *
 * Return: the number of characters printed
 */
char *rev_string(char *s)
{
	size_t len = strlen(s), i = 0;
	char tmp;


	for (; i < len / 2; ++i)
	{
	tmp = s[i];
	s[i] = s[len - i - 1];
	s[len - i - 1] = tmp;
	}

	return (s);
}

/**
 * base_len - returns length of a number in a given base
 * @num: unsigned integer number to find the length of
 * @base: integer base to find the length in
 *
 * Return: the number of characters printed
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int cnt = 0;

	while (num > 0)
	{
	num = num / base;
	cnt++;
	}
	return (cnt);
}

/**
 * print_binary - converts an unsigned int to its binary representation and
 * @list: argument list containing the unsigned int to be converted
 *
 * Return: the number of characters printed
 */
int print_binary(va_list list)
{
	unsigned int num = 0;
	int len = 0;
	char binary[32];

	num = va_arg(list, unsigned int);
	if (num == 0)
	return (_putchar('0'));

	while (num > 0)
	{
	binary[len++] = (num % 2) + '0';
	num /= 2;
	}

	binary[len] = '\0';
	_puts(rev_string(binary));
	return (len);
}
