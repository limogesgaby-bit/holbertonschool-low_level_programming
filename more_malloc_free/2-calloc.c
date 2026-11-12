#include <stdlib.h>

/**
 * _calloc - alloue de la mémoire pour un tableau et la met à zéro
 * @nmemb: nombre d'éléments
 * @size: taille d'un élément en octets
 *
 * Return: pointeur vers la mémoire allouée, initialisée à zéro,
 * ou NULL si nmemb ou size vaut 0, ou si malloc échoue
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	if (nmemb > (unsigned int)-1 / size)
		return (NULL);

	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		ptr[i] = 0;

	return (ptr);
}

/*
*#include <stdio.h>
*#include <string.h>
*
*void simple_print_buffer(char *buffer, unsigned int size);
*
*int main(void)
*{
*	char *a;
*
*	a = _calloc(98, sizeof(char));
*	if (a == NULL)
*		return (1);
*	strcpy(a, "Best");
*	strcpy(a + 4, " School! :)\n");
*	a[97] = '!';
*	simple_print_buffer(a, 98);
*	free(a);
*	return (0);
*}
*/
