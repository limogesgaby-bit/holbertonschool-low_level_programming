#include <string.h>
#include "3-calc.h"

/**
 * get_op_func - selects the function matching an operator
 * @s: operator given as argument to the program
 *
 * Return: pointer to the matching function, or NULL if no operator matches
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/*
 * Test main (commenté, à ne pas pousser en activé) :
 *
 * #include <stdio.h>
 * #include "3-calc.h"
 *
 * int main(void)
 * {
 *	int (*f)(int, int) = get_op_func("+");
 *
 *	printf("%d\n", f(1, 1));
 *	return (0);
 * }
 */
