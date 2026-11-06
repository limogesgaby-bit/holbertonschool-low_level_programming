#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: pointer to the matrix, stored as a flat array
 * @size: size of the matrix (number of rows and columns)
 *
 * Return: Nothing.
 */
void print_diagsums(int *a, int size)
{
	int i;
	long sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%ld, %ld\n", sum1, sum2);
}

/*
 * int main(void)
 * {
 *	int c3[3][3] = {
 *		{0, 1, 5},
 *		{10, 11, 12},
 *		{1000, 101, 102},
 *	};
 *
 *	print_diagsums((int *)c3, 3);
 *	return (0);
 * }
 */
