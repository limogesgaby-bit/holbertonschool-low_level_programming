#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @cmp: pointer to the function used to compare the values
 *
 * Return: index of the first element for which cmp does not return 0,
 * or -1 if no element matches or if size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || !cmp || size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

/*
 * Test main (commenté, à ne pas pousser en activé) :
 *
 * #include <stdio.h>
 * #include "function_pointers.h"
 *
 * int is_98(int elem)
 * {
 *	return (98 == elem);
 * }
 *
 * int main(void)
 * {
 *	int array[5] = {0, 402, 98, 1024, 4096};
 *
 *	printf("%d\n", int_index(array, 5, is_98));
 *	return (0);
 * }
 */
