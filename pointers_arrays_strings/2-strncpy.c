#include "main.h"

/**
 * _strncpy - copies a string using at most n bytes
 * @dest: destination buffer
 * @src: source string
 * @n: number of bytes to write in dest
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
*#include <stdio.h>
*
*int main(void)
*{
*	char s1[98];
*
*	_strncpy(s1, "First, solve the problem", 5);
*	printf("%s\n", s1);
*	return (0);
*}
*/
