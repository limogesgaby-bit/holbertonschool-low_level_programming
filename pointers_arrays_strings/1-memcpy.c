#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char src[] = "Holberton";
 *	char dest[10] = {0};
 *
 *	_memcpy(dest, src, 5);
 *	printf("%s\n", dest);
 *	return (0);
 * }
 */
