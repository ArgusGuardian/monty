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

void pint_stack(stack_t **head, unsigned int counter)
{
	(void)counter;

	printf("%d\n", (*head)->n);
}

void pop_stack(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;

	(void)counter;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	free(temp);
}

void swap_stack(stack_t **head, unsigned int counter)
{
	stack_t *first = *head;
	stack_t *second = (*head)->next;

	(void)counter;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*head = second;
}
void add_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n += top->n;
	*head = second_top;
	free(top);
}

void nop_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}

void sub_stack(stack_t **head, unsigned int counter)
{
	int result = (*head)->next->n - (*head)->n;

	(void)counter;
	pop_stack(head, counter);
	(*head)->n = result;
}

void div_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n /= top->n;
	*head = second_top;
	free(top);
}

void mul_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n *= top->n;
	*head = second_top;
	free(top);
}

void mod_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n %= top->n;
	*head = second_top;
	free(top);
}

void pchar_stack(stack_t **head, unsigned int counter)
{
	int value = (*head)->n;

	(void)counter;
	printf("%c\n", (char)value);
}
