#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct printer - matches a format specifier with a print function
 * @type: format specifier
 * @f: function to print the argument
 */
typedef struct printer
{
	char type;
	void (*f)(va_list);
} printer_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
