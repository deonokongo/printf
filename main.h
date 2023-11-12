#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int specifier(char character, va_list ap);
int escape_char(char special_char, va_list ap);
int print_num(int num, int base);
int print_string(char *character);
int print_char(int n);

#endif
