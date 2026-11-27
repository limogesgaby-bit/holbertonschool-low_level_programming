#include <stdlib.h>
#include "lists.h"

/**
* free_list - frees a list_t list
* @head: pointer to the head of the list
*/
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}

/*
*#include <stdio.h>
*#include <string.h>
*int main(void)
*{
*	list_t *head = NULL;
*
*	add_node_end(&head, "Bob");
*	add_node_end(&head, "Kris");
*	print_list(head);
*	free_list(head);
*	head = NULL;
*	return (0);
*}
*/
