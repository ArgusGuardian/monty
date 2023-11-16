#include "monty.h"

void error_handler(char *line, FILE *file, unsigned int counter, stack_t *head)
{
	if (strcmp(arguments[0], "push") == 0)
		if (!_isdigit(arguments[1]) || arguments[1] == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			free_for_all(line, file, head, arguments);
			exit(EXIT_FAILURE);
		}
	if (strcmp(arguments[0], "pint") == 0)
		if (!head)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
			exit(EXIT_FAILURE);
		}
}
