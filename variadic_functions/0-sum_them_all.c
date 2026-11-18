#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters passed to the function
 *
 * Return: the sum of the parameters, or 0 if @n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(args, n);
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);
	va_end(args);

	return (sum);
}

/*
*int main(void)
*{
*	int sum;
*
*	sum = sum_them_all(2, 98, 1024);
*	printf("%d\n", sum);
*	sum = sum_them_all(4, 98, 1024, 402, -1024);
*	printf("%d\n", sum);
*	return (0);
}
*/
