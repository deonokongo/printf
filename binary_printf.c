#include "main.h"
#include <unistd.h>

/**
 * print_binary - converts decimal number to binary
 * @n: input integer
 * Return: Success 0 or 1
 */
int print_binary(unsigned int n)
{
    int count = 0;
    int binary = 0;
   
    if (n == 0)
        return (count += print_char('0'));

    if (n == 1)
        return (count += print_char('1'));

    count += print_binary(n / 2);
    binary = n % 2;
    count += print_char('0' + binary);
    return (count);
}

