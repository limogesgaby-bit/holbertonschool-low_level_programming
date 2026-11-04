#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including the null byte,
 * to the buffer pointed to by dest
 * @dest: the destination buffer
 * @src: the source string
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char s1[98];
 *	char *ptr;
 *
 *	ptr = _strcpy(s1, "First, solve the problem. Then, write the code\n");
 *	printf("%s", s1);
 *	printf("%s", ptr);
 *	return (0);
 * }
 */
