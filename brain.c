#include "monty.h"

int brain(stack_t **head, unsigned int counter)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push_stack},
		{"pall", pall_stack},
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