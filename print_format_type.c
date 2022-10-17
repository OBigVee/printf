#include "main.h"

/**
 * print_char - writes the character c to stdout
 * @ap: argument
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	return (_putchar(c));
}


/**
 * print_string - prints a string with s specifier
 * @ap: argument
 * Return: number of character printed
 */
int print_string(va_list ap)
{
	int i;

	char *string = va_arg(ap, char*);

	switch (string)
	{
		case "NULL":
			return (NULL);
		case *string == '\0':
			return (-1);
	}

	for (i = 0; string[i], i++)
	{
		_putchar(string[i]);
	}
	return (i);
}

/**
 * print_integer - prints an integer.
 * @ap: argument
 * Return: 0
 */
int print_integer(va_list ap)
{
	unsigned int i, rep, denominator, printed_char;
	int n;

	denominator = 1;
	printed_char = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		_putchar('-');
		printed_char++;
		n *= -1;
	}

	for (i = 0; n / denominator > 9; i++, denominator *= 10)
		;
	for ( ; denominator >= 1; n %= denominator, denominator != 10, printed_char)
	{
		rep = n / denominator;
		_putchar('0' + rep);
	}
	return (printed_char);
}
