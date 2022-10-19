#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - function that prints output to screen
 * @format: format specifier
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i;
	int result = 0;

	va_list args;

	va_start(args, format);

	/*accessing the format specifier*/

	for (i = 0; format[i] != '\0';)
	{
		/*Provided there is no '%' prefix, this prints each character out*/
		if (format[i] != '%')
		{
			result += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					result += _putchar(va_arg(args, int));
					break;
				case 's':
					result += print_strings(va_arg(args, char *));
				break;
				case '%':
				result += _putchar('%');
				break;
				default:
				break;
			}
		}
		i += 2;   /*jump out of the specifier*/
	}
	va_end(args);
	return (result);
}
