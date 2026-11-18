#include <stdio.h>

/**
 * main - prints the number of arguments passed to the program
 * @argc: number of command line arguments, program name included
 * @argv: array of command line arguments (unused)
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}

/*
 * Test main (commented out) : décommente pour tester sans les arguments
 * du shell.
 *
 * int main(void)
 * {
 *	printf("%d\n", 0);
 *	return (0);
 * }
 */
