#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"

int _putchar(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

void _putchar2(char c)
{
	write(1, &c, 1);
}

int _putstr(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int _printf(const char *format, ...)
{
	int i;
	int j;
	int res;
	va_list args;
	op_t ops[] = {
		{'c', _putchar},
		{'s', _putstr},
		{'\0', NULL}
	};

	res = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			j = 0;
			while (ops[j].op)
			{
				if (ops[j].op == format[i])
				{
					res += ops[j].f(args);
				}
				j++;
			}
		}
		else
		{
			_putchar2(format[i]);
			res++;
		}
		i++;
	}
	return (res);
}
