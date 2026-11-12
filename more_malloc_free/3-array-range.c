#include <stdlib.h>

/**
 * array_range - crée un tableau d'entiers de min à max inclus
 * @min: première valeur du tableau
 * @max: dernière valeur du tableau
 *
 * Return: pointeur vers le tableau créé, ou NULL si min > max
 * ou si malloc échoue
 */
int *array_range(int min, int max)
{
	int *arr;
	unsigned int count, i;

	if (min > max)
		return (NULL);

	count = (unsigned int)max - (unsigned int)min + 1;
	arr = malloc(sizeof(int) * count);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < count; i++)
		arr[i] = min + (int)i;

	return (arr);
}

/*
*#include <stdio.h>
*
*void simple_print_buffer(int *buffer, unsigned int size);
*
*int main(void)
*{
*	int *a;
*
*	a = array_range(0, 10);
*	if (a == NULL)
*		return (1);
*	simple_print_buffer(a, 11);
*	free(a);
*	return (0);
*}
*/
