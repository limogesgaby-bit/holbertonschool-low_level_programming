#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of command line arguments (unused)
 * @argv: array of command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}

/*
 * Test main (commented out) : décommente pour tester la logique
 * sans l'option -Werror sur argc.
 *
 * int main(void)
 * {
 *	printf("%s\n", "./mynameis");
 *	return (0);
 * }
 */
