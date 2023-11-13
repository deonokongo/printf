#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - print a character
 * @n: an integer
 * Return: success 1
 */
int print_char(int n)
{
	if (n == NULL)
		return (0);
	return (write(1, &n, 1));
}

/**
 * print_string - prints a string
 * @character: a string pointer
 * Return: success 1
 */
int print_string(char *character)
{
	int i, count;

	if (character == NULL)
		return (0);

	count = 0;
	for (i = 0; character[i] != '\0'; i++)
		count += print_char((int)character[i]);
	return (count);
}

/**
 * escape_char - evaluates the special character
 * @special_char: special character
 * @ap: arguement pointer
 * Return: an integer value
 */
int escape_char(char special_char, va_list ap)
{
	int count = 0;

	if (special_char == NULL)
		return (0);

	if (special_char == 'n')
		count = write(1, "\n", 1);
	else if (special_char == 't')
		count = write(1, "\t", 1);
	else if (special_char == 'a')
		count = write(1, "\a", 1);
	else
		count += print_char(va_arg(ap, int));
	return (count);
}

/**
 * specifier - checks format spacifier
 * @character: format specifier
 * @ap: arguement pointer
 * Return: integer value
 */
int specifier(char character, va_list ap)
{
	int count = 0;

	if (character == NULL)
		return (0);

	if (character == 'c')
		return (count += print_char(va_arg(ap, int)));
	else if (character == 's')
		count += print_string(va_arg(ap, char *));
	else if (character == '%')
		count += print_char('%');
	else if (character == 'd')
		count += print_decimal((long)va_arg(ap, int));
	else if (character == 'i')
		count += print_decimal((long)va_arg(ap, int));
	else if (character == 'x')
		count += print_hexadecimal((long)va_arg(ap, unsigned int));
	else if (character == 'o'
	else
		count += print_char(va_arg(ap, int));
	return (count);
}

/**
 * _printf - variadic function replacing printf
 * @format: poiter to format string
 * Return: success 0 or 1
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list ap;

	if (format == NULL)
		return (-1);

	i = 0;
	count = 0;
	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			count += specifier(format[i + 1], ap);
			i++;
		}
		else if (format[i] == '\\')
		{
			count += escape_char(format[i + 1], ap);
			i++;
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(ap);
	return (count);
}
