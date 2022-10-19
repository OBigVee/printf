#include "main.h"

/**
 * print_decimal - prints integer values
 * @num: integer to be printed
 *
 * Return: int
 */

int print_decimal(int num)
{
	int result = 0;

	if (num < 0)
	{
		result += _putchar('-');
		num = num * -1;
	}

	/**
	 * print numbers using recursion by removing last digits and
	 * print the remaining, then finally print the last digit
	 */

	if (num / 10)
	{
		result += print_decimal(num / 10);
	}

	result += _putchar(num % 10 + '0');
	return (result);
}
