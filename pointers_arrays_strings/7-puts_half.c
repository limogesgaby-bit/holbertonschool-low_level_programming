#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a new line
 * @str: the string to print
 *
 * Description: if the length is odd, prints the last (length + 1) / 2
 * characters.
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
		len++;

	for (i = len / 2; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/*
 * int main(void)
 * {
 *	char *str;
 *
 *	str = "0123456789";
 *	puts_half(str);
 *	return (0);
 * }
 */
