#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements in the array
 *
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	int i = 0, tmp;

	while (i < n / 2)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
		i++;
	}
}

/*
#include <stdio.h>

int main(void)
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 98, 1024, 1337};
	int i;

	reverse_array(a, sizeof(a) / sizeof(int));
	for (i = 0; i < (int)(sizeof(a) / sizeof(int)); i++)
		printf("%d ", a[i]);
	printf("\n");
	return (0);
}
*/
