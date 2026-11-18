#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies the two numbers passed as arguments
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, 1 if the number of arguments is wrong
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}

/*
 * Test main (commented out) : décommente pour tester sans le shell.
 *
 * int main(void)
 * {
 *	printf("%d\n", atoi("245") * atoi("3245342"));
 *	return (0);
 * }
 */
