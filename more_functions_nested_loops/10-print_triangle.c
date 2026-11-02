#include "main.h"

/**
 * print_triangle - prints a triangle with the character #
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = 0; j < size - i; j++)
			_putchar(' ');
		for (j = 0; j < i; j++)
			_putchar('#');
		_putchar('\n');
	}
	if (size <= 0)
		_putchar('\n');
}

/*
 * int main(void)
 * {
 *     print_triangle(2);
 *     print_triangle(10);
 *     print_triangle(0);
 *     return (0);
 * }
 */
