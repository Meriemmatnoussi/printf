#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
  *_putchar - writes a character to stdou
  *@c: character to print
  *
  *Return: on succes 1.On error,-1 is returned,and errno is set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
  *_puts _prints a string to stdout
  *@str: pointer to string to print
  *
  *Return: the number of characters printed
  */
int _puts(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
{
		count += _putchar(*str);
		str++;
}

	return (count);
}
