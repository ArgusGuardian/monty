#include "monty.h"

void error_handler(char *line, FILE *file, unsigned int counter, stack_t **head)
{
	if (strcmp(arguments[0], "push") == 0)
		if (!_isdigit(arguments[1]) || arguments[1] == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer", counter);
			free_for_all(line, file, head);
			exit(EXIT_FAILURE);
		}
}
