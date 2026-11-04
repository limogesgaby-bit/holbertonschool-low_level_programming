#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string to print
 *
 * Return: nothing
 */
void puts_half(char *str)
{
	int len = 0, i;

	while (str[len] != '\0')
		len++;

	for (i = (len + 1) / 2; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

/*
 * int main(void)
 * {
 *     puts_half("0123456789");
 *     puts_half("Lorem ipsum");
 *     puts_half("");
 *     return (0);
 * }
 */
