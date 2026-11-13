#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to the struct dog to initialize
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}

/*
*int main(void)
*{
*	struct dog my_dog;
*
*	init_dog(&my_dog, "Poppy", 3.5, "Bob");
*	printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
*	return (0);
*}
*/
