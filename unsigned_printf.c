#include "main.h"
#include <unistd.h>
/**
 * print_positive - prints positive integers
 * @n: input value
 * Return: the number of characters printed
 */
int print_positive(unsigned int n)
{
	int count = 0;

	if (n == 0)
	{
		print_char('0');
		return (1);
	}

	count += print_positive(n / 10);
	count += print_char('0' + n % 10);

	return (count);
}
/**
 * print_uppercase - prints characters in uppercase
 * @n: hexadecimal input character
 * Return: number of printed characters
 */
int print_uppercase(int n)
{
	int i;
	int count = 0;
	char *hex_chars = "0123456789ABCDEF";

	for (i = 0; hex_chars[i] != '\0'; i++)
	{
		if ((n >= 0 && n <= 9) || (n >= 'A' && n <= 'F'))
		{
			count += print_char(hex_chars[i]);
			break;
		}
	}

	return (count);
}
