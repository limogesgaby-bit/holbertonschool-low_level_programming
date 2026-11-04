#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: the string to print
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/*
 * int main(void)
 * {
 *	char *str;
 *
 *	str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
 *	_puts(str);
 *	return (0);
 * }
 */
