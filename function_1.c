#include "monty.h"

void push_stack(stack_t **head, unsigned int counter)
{
	int data;
	stack_t *new;
	(void)counter;

	data = atoi(arguments[1]);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(arguments);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	new->n = data;

	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		new->next = NULL;
		new->prev = *head;
		*head = new;
	}
}

void pall_stack(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	(void)counter;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
