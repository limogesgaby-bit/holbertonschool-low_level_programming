#include <stdlib.h>
#include "dog.h"

/**
 * copy_string - allocates a copy of a string
 * @s: string to copy
 *
 * Return: pointer to the new copy, or NULL on failure
 */
static char *copy_string(char *s)
{
	char *copy;
	int len = 0;
	int i;

	while (s[len])
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		copy[i] = s[i];
	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog (copied)
 * @age: age of the dog
 * @owner: name of the owner (copied)
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = copy_string(name);
	d->owner = copy_string(owner);
	if (d->name == NULL || d->owner == NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
		return (NULL);
	}
	d->age = age;
	return (d);
}

/*
*#include <stdio.h>
*int main(void)
*{
*	dog_t *my_dog;
*
*	my_dog = new_dog("Poppy", 3.5, "Bob");
*	printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
*	free(my_dog->name);
*	free(my_dog->owner);
*	free(my_dog);
*	return (0);
*}
*/
