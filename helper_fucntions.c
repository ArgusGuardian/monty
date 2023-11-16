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
/**
 * free_for_all - Frees allocated memory and closes file.
 * @line: Pointer to the dynamically allocated line.
 * @file: File stream to be closed.
 * @head: Pointer to the head of a stack.
 * @arguments: Pointer to an array of command arguments.
 */
void free_for_all(char *line, FILE *file, stack_t *head, char **arguments)
{
	if (line)
		free(line);
	fclose(file);
	free_stack(head);
	free(arguments);
}
/**
 * free_stack - Frees a stack.
 * @head: Pointer to the head of a stack.
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		(head) = current->next;
		free(current);
	}
}
/**
 * check_line - Checks if a line contains non-whitespace characters.
 * @line: Pointer to the line to be checked.
 * Return: 1 if the line contains non-whitespace characters, 0 otherwise.
 */
int check_line(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
