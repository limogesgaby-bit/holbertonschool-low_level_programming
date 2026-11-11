#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);

	return (p);
}

/*
*Test à décommenter pour compiler localement :
*#include <stdio.h>
*#include <limits.h>
*
*int main(void)
*{
*	char *c;
*	int *i;
*
*	c = malloc_checked(sizeof(char) * 1024);
*	printf("%p\n", (void *)c);
*	i = malloc_checked(INT_MAX);
*	printf("%p\n", (void *)i);
*	free(c);
*	free(i);
*	return (0);
*}
*/
