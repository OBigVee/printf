#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);

int print_char(va_list ap);

int print_string(va_list ap);

int print_integer(va_list ap);

int _printf(const char *format, ...);

/**
 * struct print_format - print properties
 * @format_id: format identifier
 * @printer: function pointer that takes the function as parameter
 * the function prints the correct format base on format_id.
 */
typedef struct print_format
{
	char *format_id;
	int (*printer)(va_list);
} print_format;

#endif /* PRINTF_H */
