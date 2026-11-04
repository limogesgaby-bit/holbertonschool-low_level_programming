#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int len = 0;
	int i = 0;
	char tmp;

	while (s[len] != '\0')
		len++;

	while (i < len - 1 - i)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
}

/*
 * #include <stdio.h>
 *
 * int main(void)
 * {
 *	char s[10] = "My School";
 *
 *	printf("%s\n", s);
 *	rev_string(s);
 *	printf("%s\n", s);
 *	return (0);
 * }
 */
