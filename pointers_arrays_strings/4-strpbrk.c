#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: bytes to match
 *
 * Return: pointer to matching byte or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s != '\0')
	{
		a = accept;

		while (*a != '\0')
		{
			if (*s == *a)
			{
				return (s);
			}

			a++;
		}

		s++;
	}

	return (0);
}
