#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the first node of the list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		count++;
	}
	return (count);
}

/*
*#include <stdlib.h>
*#include <string.h>
*#include "lists.h"
*
*int main(void)
*{
*	list_t *head;
*	list_t *new;
*	list_t hello = {"World", 5, NULL};
*	size_t n;

*	head = &hello;
*	new = malloc(sizeof(list_t));
*	if (new == NULL)
*		return (1);
*	new->str = strdup("Hello");
*	new->len = 5;
*	new->next = head;
*	head = new;
*	n = print_list(head);
*	printf("-> %lu elements\n", n);
*
*	free(new->str);
*	free(new);
*	return (0);
*}
*/
