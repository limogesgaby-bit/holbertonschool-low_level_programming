#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @action: pointer to the function to execute on each element
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}

/*
 * Test main (commenté, à ne pas pousser en activé) :
 *
 * #include <stdio.h>
 * #include "function_pointers.h"
 *
 * void print_elem(int elem)
 * {
 *	printf("%d\n", elem);
 * }
 *
 * int main(void)
 * {
 *	int array[5] = {0, 98, 402, 1024, 4096};
 *
 *	array_iterator(array, 5, &print_elem);
 *	return (0);
 * }
 */
