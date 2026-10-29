#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase, followed by a new line
 *
 * Return: Nothing.
 */
void print_alphabet(void)
{
\tchar c;

\tfor (c = 'a'; c <= 'z'; c++)
\t\t_putchar(c);
\t_putchar('\\n');
}
