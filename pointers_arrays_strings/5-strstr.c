#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to find
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*n && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (haystack);
		haystack++;
	}

	if (*needle == '\0')
		return (haystack);

	return (0);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char *p;
 *
 *	p = _strstr("hello, world", "wor");
 *	if (p)
 *		printf("%s\n", p);
 *	p = _strstr("hello", "xyz");
 *	if (!p)
 *		printf("not found\n");
 *	return (0);
 * }
 */
