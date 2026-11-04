#include "main.h"

/**
 * reset_to_98 - updates the value pointed to by n to 98
 * @n: pointer to an int
 *
 * Return: void
 */
void reset_to_98(int *n)
{
	*n = 98;
}

/*
 * Test main (décommente pour tester, puis recommente avant de push)
 *
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	int n;
 *
 *	n = 402;
 *	printf("n=%d\n", n);
 *	reset_to_98(&n);
 *	printf("n=%d\n", n);
 *	return (0);
 * }
 */
