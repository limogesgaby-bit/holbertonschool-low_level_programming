#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @n: the integer
 *
 * Return: the absolute value of n.
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* TEST
int main(void)
{
	int r;

	r = _abs(-1);
	_putchar(r / 10 + '0');
	_putchar(r % 10 + '0');
	_putchar('\n');
	r = _abs(0);
	_putchar(r / 10 + '0');
	_putchar(r % 10 + '0');
	_putchar('\n');
	r = _abs(1);
	_putchar(r / 10 + '0');
	_putchar(r % 10 + '0');
	_putchar('\n');
	r = _abs(-98);
	_putchar(r / 10 + '0');
	_putchar(r % 10 + '0');
	_putchar('\n');
	return (0);
}
TEST */
