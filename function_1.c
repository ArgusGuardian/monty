#include "monty.h"
/**
 * push_stack - push to stack
 * @counter: line number
 * @head: head of stack
 */
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
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = NULL;
	new->prev = NULL;

	if (!(*head))
		(*head) = new;
	else
	{
		new->next = *head;
		(*head)->prev = new;
		(*head) = new;
	}
}
/**
 * pall_stack - print all stack
 * @counter: line number
 * @head: head of stack
 */
void pall_stack(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		fflush(stdout);
		current = current->next;
	}
}
/**
 * pint_stack - print head of stack
 * @counter: line number
 * @head: head of stack
 */
void pint_stack(stack_t **head, unsigned int counter)
{
	(void)counter;

	printf("%d\n", (*head)->n);
}
/**
 * pop_stack - remove the head of stack
 * @counter: line number
 * @head: head of stack
 */
void pop_stack(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;

	(void)counter;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	free(temp);
}

/**
 * rotr_stack - rotate top to bottom and vice versa
 * @counter: line number
 * @head: head of stack
 */
void rotr_stack(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *head;
	(*head)->prev = current;
	*head = current;
}
