#include <stdio.h>

/**
 * main - prints all the arguments it receives, one per line
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}

/*
 * Test main (commented out) : décommente pour tester la boucle
 * sans passer d'arguments au shell.
 *
 * int main(void)
 * {
 *	char *args[] = {"./args", "You", "can", NULL};
 *	int i;
 *
 *	for (i = 0; args[i]; i++)
 *		printf("%s\n", args[i]);
 *	return (0);
 * }
 */
