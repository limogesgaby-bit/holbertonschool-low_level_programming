#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: pointer to the struct dog to print
 *
 * Description: NULL elements are printed as (nil). Nothing if d is NULL.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}

/*
*int main(void)
*{
*	struct dog my_dog;
*
*	my_dog.name = "Poppy";
*	my_dog.age = 3.5;
*	my_dog.owner = "Bob";
*	print_dog(&my_dog);
*	return (0);
*}
*/
