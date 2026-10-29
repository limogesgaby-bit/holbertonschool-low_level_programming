#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: Nothing.
 */
void times_table(void)
{
	int i, j, p;

	for (i = 0; i <= 9; i++)
	{
		_putchar('0');
		for (j = 1; j <= 9; j++)
		{
			p = i * j;
			_putchar(',');
			_putchar(' ');
			if (p < 10)
				_putchar(' ');
			else
				_putchar(p / 10 + '0');
			_putchar(p % 10 + '0');
		}
		_putchar('\n');
	}
}

/* TEST
int main(void)
{
	times_table();
	return (0);
}
TEST */
