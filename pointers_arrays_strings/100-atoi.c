#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description: every '-' before the first digit flips the sign. The number
 * is built as a negative value so that the most negative int never overflows
 * while accumulating.
 *
 * Return: the converted number, or 0 if there is no digit in the string
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int n = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			n = n * 10 - (s[i] - '0');
		}
		else if (started)
			break;
		else if (s[i] == '-')
			sign = -sign;
		i++;
	}

	if (sign == 1)
		return (-n);
	return (n);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	int nb;
 *
 *	nb = _atoi("98");
 *	printf("%d\n", nb);
 *	nb = _atoi("-402");
 *	printf("%d\n", nb);
 *	nb = _atoi(" ------++++++-----+++++--98");
 *	printf("%d\n", nb);
 *	nb = _atoi("214748364");
 *	printf("%d\n", nb);
 *	nb = _atoi("0");
 *	printf("%d\n", nb);
 *	nb = _atoi("Suite 402");
 *	printf("%d\n", nb);
 *	nb = _atoi(" + + - -98 Battery Street; San Francisco, CA 94111 - USA ");
 *	printf("%d\n", nb);
 *	nb = _atoi("---++++ -++ Sui - te - 402 #cisfun :)");
 *	printf("%d\n", nb);
 *	return (0);
 * }
 */
