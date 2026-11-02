#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char c;
 *
 *	c = '0';
 *	printf("%c: %d\n", c, _isdigit(c));
 *	c = 'a';
 *	printf("%c: %d\n", c, _isdigit(c));
 *	return (0);
 * }
 */
