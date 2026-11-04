#include "main.h"

/**
 * puts2 - prints every other character of a string, starting with the first
 * @str: the string to print
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 2;
	}
	_putchar('\n');
}

/*
 * int main(void)
 * {
 *	char *str;
 *
 *	str = "0123456789";
 *	puts2(str);
 *	return (0);
 * }
 */
