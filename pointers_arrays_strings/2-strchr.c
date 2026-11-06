#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to find
 *
 * Return: pointer to the first occurrence of c, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (1)
	{
		if (*s == c)
			return (s);
		if (*s == '\0')
			return (0);
		s++;
	}
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char *s = "Holberton";
 *	char *p;
 *
 *	p = _strchr(s, 'b');
 *	if (p)
 *		printf("%s\n", p);
 *	p = _strchr(s, 'z');
 *	if (!p)
 *		printf("not found\n");
 *	return (0);
 * }
 */
