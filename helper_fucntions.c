#include "monty.h"

/**
 * _isdigit - checks if c is a digit
 * @str: charcter to check
 * Return: 1 if digit and 0 if not
 */
int _isdigit(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

void free_for_all(char *line, FILE *file, stack_t **head)
{
	if (line)
		free(line);
	fclose(file);
	free_stack(head);
	free(arguments);
}

void free_stack(stack_t **head)
{
	stack_t *current;

	while (*head != NULL)
	{
		current = *head;
		*head = current->next;
		free(current);
	}
}
