#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Return: pointer to str
 */
char *leet(char *str)
{
	int i, j;
	char from[] = "aAeEoOtTlL";
	char to[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; from[j] != '\0'; j++)
		{
			if (str[i] == from[j])
			{
				str[i] = to[j];
				break;
			}
		}
	}
	return (str);
}

/*
*#include <stdio.h>
*
*int main(void)
*{
*	char s[] = "Expect the best. Prepare for the worst.\n";
*
*	printf("%s", leet(s));
*	return (0);
*}
*/
