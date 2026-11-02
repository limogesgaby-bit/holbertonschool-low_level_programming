#include "main.h"

/**
 * _isupper - checks for uppercase character
 * @c: character to check
 *
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/**
 * #include <stdio.h>
 *
 * int main(void)
 * {
 * 	printf("%c: %d\n", 'A', _isupper('A'));
 * 	printf("%c: %d\n", 'a', _isupper('a'));
 * 	return (0);
 * }
 */
 