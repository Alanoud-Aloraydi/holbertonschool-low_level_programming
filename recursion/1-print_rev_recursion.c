/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: On success 1.
 */
int _putchar(char c);

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: string to print
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
