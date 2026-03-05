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
	int i = 0, sign = 1, started = 0;
	int num = 0;

	while (s[i] != '\0')
	{
		if (!started)
		{
			if (s[i] == '-')
				sign *= -1;
			else if (s[i] >= '0' && s[i] <= '9')
				started = 1;
		}

		if (started)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int digit = s[i] - '0';

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
			}
			else
			{
				break;
			}
		}

		i++;
	}

	if (!started)
		return (0);

	return (num);
}
