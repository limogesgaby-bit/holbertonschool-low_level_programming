#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to scan
 * @accept: set of accepted characters
 *
 * Return: number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *a;
	int found;

	while (*s)
	{
		found = 0;
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		count++;
		s++;
	}

	return (count);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	printf("%u\n", _strspn("hello, world", "oleh"));
 *	printf("%u\n", _strspn("hello", "xyz"));
 *	return (0);
 * }
 */
