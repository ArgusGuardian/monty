#include "monty.h"
/**
 * brain - handling error
 * @counter: line number
 * @head: head of stack
 * Return: one if function opcode is valid 0 if not
 */
int brain(stack_t **head, unsigned int counter)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{NULL, NULL}};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, arguments[0]) == 0)
		{
			opcodes[i].f(head, counter);
			return (1);
		}
		i++;
	}
	return (-1);
}
