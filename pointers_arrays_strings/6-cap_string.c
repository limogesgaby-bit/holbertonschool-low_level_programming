#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
	int i = 0, j, new_word = 1;
	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		new_word = 0;
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i] == sep[j])
				new_word = 1;
		}
		i++;
	}
	return (str);
}

/*
*#include <stdio.h>
*
*int main(void)
*{
*	char str[] = "hello world! hello-world 0123456hello world\thello world.hello world\n";
*
*	printf("%s", cap_string(str));
*	return (0);
*}
*/
