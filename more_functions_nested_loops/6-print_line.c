#include "main.h"

/**
 * print_line - draws a straight line of underscores
 * @n: number of times the character should be printed
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
		_putchar('_');
	_putchar('\n');
}

/*
 * int main(void)
 * {
 *     print_line(2);
 *     print_line(10);
 *     print_line(0);
 *     return (0);
 * }
 */
