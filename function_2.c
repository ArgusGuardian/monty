#include "monty.h"

/**
 * swap_stack - swasp last 2 elements in stack
 * @counter: line number
 * @head: head of stack
 */
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
/**
 * add_stack - add last 2 elements of stack
 * @counter: line number
 * @head: head of stack
 */
void add_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n += top->n;
	*head = second_top;
	free(top);
}
/**
 * nop_stack - do nothing
 * @counter: line number
 * @head: head of stack
 */
void nop_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}
/**
 * sub_stack - sub the last from the previous
 * @counter: line number
 * @head: head of stack
 */
void sub_stack(stack_t **head, unsigned int counter)
{
	int result = (*head)->next->n - (*head)->n;

	(void)counter;
	pop_stack(head, counter);
	(*head)->n = result;
}
/**
 * div_stack - div of the last 2 elements in stack
 * @counter: line number
 * @head: head of stack
 */
void div_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *second_top = top->next;

	(void)counter;
	second_top->n /= top->n;
	*head = second_top;
	free(top);
}
