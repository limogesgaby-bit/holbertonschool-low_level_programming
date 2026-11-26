#include <stddef.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to the first node of the list
 *
 * Return: the number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/*
*#include <stdlib.h>
*#include <string.h>
*#include <stdio.h>
*#include "lists.h"

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
*	n = list_len(head);
*	printf("-> %lu elements\n", n);
*	free(new->str);
*	free(new);
*	return (0);
*}
*/
