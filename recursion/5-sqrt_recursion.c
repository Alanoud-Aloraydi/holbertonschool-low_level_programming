/**
 * helper - finds the natural square root using recursion
 * @n: number to find square root of
 * @i: current guess
 *
 * Return: natural square root or -1
 */
int helper(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return helper(n, i + 1);
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root of
 *
 * Return: natural square root or -1 if it does not exist
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return helper(n, 0);
}
