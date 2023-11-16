#include "monty.h"

/**
 * mul_stack - multiply the last 2 elements of stack
 * @counter: line number
 * @head: head of stack
 */
void mul_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n *= top->n;
	*head = second_top;
	free(top);
}
/**
 * mod_stack - mod of the last 2 elements of the stack
 * @counter: line number
 * @head: head of stack
 */
void mod_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n %= top->n;
	*head = second_top;
	free(top);
}
/**
 * pchar_stack - print the head of stack as char
 * @counter: line number
 * @head: head of stack
 */
void pchar_stack(stack_t **head, unsigned int counter)
{
	int value = (*head)->n;

	(void)counter;
	printf("%c\n", (char)value);
}
/**
 * pstr_stack - print work in char from stack
 * @counter: line number
 * @head: head of stack
 */
void pstr_stack(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head;

	(void)counter;
	while (tmp != NULL && tmp->n != 0 && tmp->n >= 0 && tmp->n <= 127)
	{
		putchar((char)tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * rotl_stack - rotate by one
 * @counter: line number
 * @head: head of stack
 */
void rotl_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *current = *head;

	(void)counter;
	if (*head == NULL || (*head)->next == NULL)
		return;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = top;
	top->prev = current;
	top->next = NULL;
}
