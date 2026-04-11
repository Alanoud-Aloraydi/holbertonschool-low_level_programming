#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	unsigned int i;
	char *sep;
	char *str;
	va_list args;

	va_start(args, format);
	i = 0;
	sep = "";

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == 'c')
		{
			printf("%s%c", sep, va_arg(args, int));
			sep = ", ";
		}
		if (format[i] == 'i')
		{
			printf("%s%d", sep, va_arg(args, int));
			sep = ", ";
		}
		if (format[i] == 'f')
		{
			printf("%s%f", sep, va_arg(args, double));
			sep = ", ";
		}
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sep, str);
			sep = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
