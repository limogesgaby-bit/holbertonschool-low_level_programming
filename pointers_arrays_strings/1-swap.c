#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to the first int
 * @b: pointer to the second int
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
 * Test main (décommente pour tester, puis recommente avant de push)
 *
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	int a;
 *	int b;
 *
 *	a = 98;
 *	b = 42;
 *	printf("a=%d, b=%d\n", a, b);
 *	swap_int(&a, &b);
 *	printf("a=%d, b=%d\n", a, b);
 *	return (0);
 * }
 */
