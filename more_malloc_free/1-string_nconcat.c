#include <stdlib.h>

/**
 * string_nconcat - concatène s1 et les n premiers octets de s2
 * @s1: première chaîne
 * @s2: chaîne dont on prend au plus n octets
 * @n: nombre maximal d'octets de s2 à concaténer
 *
 * Return: pointeur vers la nouvelle chaîne allouée, ou NULL en cas d'échec
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *res;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	if (n > len2)
		n = len2;

	res = malloc(sizeof(char) * (len1 + n + 1));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];
	res[i + j] = '\0';

	return (res);
}

/*
*#include <stdio.h>
*
*int main(void)
*{
*	char *r = string_nconcat("Hello ", "World", 3);
*
*	if (r == NULL)
*		return (1);
*	printf("%s\n", r);
*	free(r);
*	return (0);
*}
*/