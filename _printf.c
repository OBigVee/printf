#include "main.h"
#include <stdio.h>

/**
 * print_specifier - prints special characters
 * @next: character after the % to identify specifiers type
 * @ap: argument for the specifier e.g %i, %d e.t.c
 * Return: the number of characters printed
 */
int print_specifier(char next, va_list ap)
{
	int idx;
	print_format specifier[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	for (idx = 0; specifier[idx].format_id != NULL; idx++)
	{
		if (specifier[idx].format_id[0] == next)
			return (specifier[idx].printer(ap));
	}

	return (0);
}

/**
 * _printf - function produces output according to a format
 * it returns the numbers of characters printed excluding the null byte used
 * to end output to strings.
 * write output to stdout, the standard output stream
 * @format: is a character string. The format string is composed of zero or
 * more directives.
 *  Return: -1 if specifier can't be identified, hence (error)
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	int id_printed, c_printed;
	va_list ap;

	id_printed = 0;
	c_printed = 0;
	va_start(ap, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			c_printed++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			c_printed++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		id_printed = print_specifier(format[i + 1], ap);

		if (id_printed == -1 || id_printed != 0)
			i++;
		if (id_printed > 0)
			c_printed += id_printed;
		if (id_printed == 0)
		{
			_putchar('%');
			c_printed++;
		}
	}
	va_end(ap);
	return (c_printed);
}
