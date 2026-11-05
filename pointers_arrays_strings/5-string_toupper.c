#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: string to modify
 *
 * Return: pointer to str
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

/*
*#include <stdio.h>
*
*int main(void)
*{
*	char str[] = "Look up!\n";
*	char *ptr;
*
*	ptr = string_toupper(str);
*	printf("%s", ptr);
*	printf("%s", str);
*	return (0);
*}
*/
