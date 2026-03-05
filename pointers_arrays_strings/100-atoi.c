#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer found in the string, or 0 if none
 */
int _atoi(char *s)
{
	char *p = s;
	int sign = 1;
	int num = 0;

	while (*p != '\0' && (*p < '0' || *p > '9'))
	{
		if (*p == '-')
			sign *= -1;
		p++;
	}

	if (*p == '\0')
		return (0);

	while (*p >= '0' && *p <= '9')
	{
		int digit = *p - '0';

		if (sign == 1)
		{
			if (num > (INT_MAX - digit) / 10)
				return (INT_MAX);
			num = num * 10 + digit;
		}
		else
		{
			if (num < (INT_MIN + digit) / 10)
				return (INT_MIN);
			num = num * 10 - digit;
		}

		p++;
	}

	return (num);
}
