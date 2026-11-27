#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node_end - adds a new node at the end of a list_t list
* @head: pointer to the pointer to the head of the list
* @str: string to duplicate and store in the new node
*
* Return: address of the new element, or NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *last;

	if (head == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = 0;
	while (new->str[new->len] != '\0')
		new->len++;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;

	return (new);
}

/*
*#include <stdio.h>
*int main(void)
*{
*
*	list_t *head = NULL;
*	add_node_end(&head, "Anne");
*	add_node_end(&head, "Colton");
*	add_node_end(&head, "Corbin");
*	print_list(head);
*	return (0);
*}
*/
