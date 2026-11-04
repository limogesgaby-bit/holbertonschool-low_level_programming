#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: the string to print
 */
void print_rev(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	while (len > 0)
	{
		len--;
		_putchar(s[len]);
	}
	_putchar('\n');
}

/*
 * int main(void)
 * {
 *	char *str;
 *
 *	str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
 *	print_rev(str);
 *	return (0);
 * }
 */
