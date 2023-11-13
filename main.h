#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int specifier(char character, va_list ap);
int escape_char(char special_char, va_list ap);
int print_num(int num, int base);
int print_string(char *character);
int print_char(int n);
int print_hexadecimal(int n);
int print_decimal(int n);
int octalToDecimalRecursive(int octalNumber, int placeValue);
int octalToDecimal(int octalNumber);

#endif
