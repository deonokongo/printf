#include "main.h"

int main(void)
{
    int decimal;

    // Test case 1: Positive number
    decimal = 10;
    printf("Decimal: %d\tBinary: ", decimal);
    print_binary(decimal);
    putchar('\n');

    // Test case 2: Another positive number
    decimal = 15;
    printf("Decimal: %d\tBinary: ", decimal);
    print_binary(decimal);
    putchar('\n');

    // Test case 3: Larger positive number
    decimal = 127;
    printf("Decimal: %d\tBinary: ", decimal);
    print_binary(decimal);
    putchar('\n');

    // Test case 4: Negative number
    decimal = -10;
    printf("Decimal: %d\tBinary: ", decimal);
    print_binary(decimal);
    putchar('\n');

    return 0;
}

