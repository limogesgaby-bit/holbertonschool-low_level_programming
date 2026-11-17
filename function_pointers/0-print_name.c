#include "function_pointers.h"

/**
 * print_name - prints a name using the function given as argument
 * @name: name to print
 * @f: pointer to the function used to print the name
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}

/*
 * Test main (commenté, à ne pas pousser en activé) :
 *
 * #include <stdio.h>
 * #include "function_pointers.h"
 *
 * void print_name_as_is(char *name)
 * {
 * 	printf("Hello, my name is %s\n", name);
 * }
 *
 * int main(void)
 * {
 * 	print_name("Bob", print_name_as_is);
 * 	return (0);
 * }
 */
