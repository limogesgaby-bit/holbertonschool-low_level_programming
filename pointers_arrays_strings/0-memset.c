#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area to fill
 * @b: the constant byte to write
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char buffer[10] = {0};
 *	int i;
 *
 *	_memset(buffer, 'A', 5);
 *	for (i = 0; i < 10; i++)
 *		printf("%d ", buffer[i]);
 *	printf("\n");
 *	return (0);
 * }
 */
