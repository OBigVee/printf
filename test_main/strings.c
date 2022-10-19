#include "main.h"

/**
 * print_strings - function that print strings
 * @string: string to print
 * Return: always 0
 */

int print_strings(char *string)
{
	int i;
	int total = 0;

	for (i = 0; string[i] != '\0'; i++)
		total = total + _putchar(string[i]);

	return (total);
}
