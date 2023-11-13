/**
 * print_hexadecimal - print numbers in hexadeximal format
 * @n: integer
 * Return: integer or 0
*/
int print_hexadecimal(int n)
{
	int count = 0;
	char *hex_chars = "0123456789abcdef";

	if (n < 0)
		return (count += write(1, "-", 1));

	if (n < 16)
		return (count += write(1, &hex_chars[n], 1));

	count += print_hexadecimal(n / 16);
	return (count += print_hexadecimal(n % 16));
}

/**
 * print_decimal - prints a number to base 10
 * @n: nuber of interest
 * Return: an interger or 0
 */
int print_decimal(int n)
{
	int count = 0;

	char *dec_chars = "0123456789";

	if (n < 0)
	{
		count += write(1, "-", 1);
		count += print_decimal(-n);
		return (count);
	}
	if (n < 10)
	{
		count += write(1, &dec_chars[n], 1);
		return (count);
	}
	count += print_decimal(n / 10);
	count += print_decimal(n % 10);
	return (count);
}

/**
 * octalToDecimalRecursive - handles recursion
 * @octalNumber: the octal
 * @placeValue: shows number place value operation
 * Return: integer or 0
 */
int octalToDecimalRecursive(int octalNumber, int placeValue)
{
	if (octalNumber == 0)
		return (0);
	else
		return ((octalNumber % 10) * placeValue +
				octalToDecimalRecursive(octalNumber / 10, placeValue * 8));
}

/**
 * octalToDecimal - converts an octal to decimal
 *                  with recursion;
 * @octalNumber: number in base 8
 * Return: integer or error
 */
int octalToDecimal(int octalNumber)
{
	int num, count = 0;

	num = octalToDecimalRecursive(octalNumber, 1);
		return (count += write(1, &num, 1));
}
