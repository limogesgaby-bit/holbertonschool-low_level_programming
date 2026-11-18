#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * is_positive_number - checks that a string contains only digits
 * @s: string to check
 *
 * Return: 1 if every character is a digit, 0 otherwise
 */
int is_positive_number(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * main - adds the positive numbers passed as arguments
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, 1 if an argument is not a number
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (!is_positive_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}

/*
 * Test main (commented out) : décommente pour tester sans le shell.
 *
 * int main(void)
 * {
 *	printf("%d\n", is_positive_number("1234") &&
 *		is_positive_number("12a") == 0);
 *	return (0);
 * }
 */
