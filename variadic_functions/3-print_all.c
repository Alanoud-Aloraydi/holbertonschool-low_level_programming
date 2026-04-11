#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: list of arguments
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: list of arguments
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: list of arguments
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list args;
	printer_t p[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};
	unsigned int i;
	unsigned int j;
	char *sep;

	va_start(args, format);
	i = 0;
	sep = "";
	while (format && format[i])
	{
		j = 0;
		while (p[j].type)
		{
			if (format[i] == p[j].type)
			{
				printf("%s", sep);
				p[j].f(args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
