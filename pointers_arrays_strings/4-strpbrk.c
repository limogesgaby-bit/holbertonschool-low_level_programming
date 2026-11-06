#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: set of bytes to look for
 *
 * Return: pointer to the first byte in s that matches one of
 * the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
				return (s);
		}
		s++;
	}

	return (0);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char *p;
 *
 *	p = _strpbrk("hello, world", " ,");
 *	if (p)
 *		printf("%s\n", p);
 *	p = _strpbrk("hello", "xyz");
 *	if (!p)
 *		printf("not found\n");
 *	return (0);
 * }
 */
