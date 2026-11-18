#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *          c: char, i: integer, f: float, s: char *
 *          any other character is ignored
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	int printed = 0;
	char *str;

	va_start(args, format);
	while (format && format[i])
	{
		if (printed && (format[i] == 'c' || format[i] == 'i' ||
				format[i] == 'f' || format[i] == 's'))
			printf(", ");
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				printed = 1;
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				printed = 1;
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				printed = 1;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				printed = 1;
				break;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}

/*
 * int main(void)
 * {
 *	print_all("ceis", 'B', 3, "stSchool");
 *	return (0);
 * }
 */
