#include "monty.h"
/**
 * error_1 - handling error
 * @line: current line
 * @file: pointer to file
 * @counter: line number
 * @head: head of stack
 */
void error_1(char *line, FILE *file, unsigned int counter, stack_t *head)
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
	if (strcmp(arguments[0], "pop") == 0)
		if (!head)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
			exit(EXIT_FAILURE);
		}
	if (strcmp(arguments[0], "swap") == 0)

		if (!head || !head->next)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
			exit(EXIT_FAILURE);
		}
	if (strcmp(arguments[0], "add") == 0)
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", counter);
			free_for_all(line, file, head, arguments);
			exit(EXIT_FAILURE);
		}
}
/**
 * error_2 - handling error
 * @line: current line
 * @file: pointer to file
 * @counter: line number
 * @head: head of stack
 */
void error_2(char *line, FILE *file, unsigned int counter, stack_t *head)
{
	if (strcmp(arguments[0], "sub") == 0)
		if (!head || !head->next)
		{
			fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
			free_for_all(line, file, head, arguments);
			exit(EXIT_FAILURE);
		}
	if (strcmp(arguments[0], "div") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L%d: can't div, stack too short\n", counter);
			exit(EXIT_FAILURE);
		}

		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", counter);
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(arguments[0], "mul") == 0)
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
			exit(EXIT_FAILURE);
		}
	if (strcmp(arguments[0], "mod") == 0)
	{
		if (head == NULL || head->next == NULL)
		{
			fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
			exit(EXIT_FAILURE);
		}
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", counter);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * error_3 - handling error
 * @line: current line
 * @file: pointer to file
 * @counter: line number
 * @head: head of stack
 */
void error_3(char *line, FILE *file, unsigned int counter, stack_t *head)
{
	if (strcmp(arguments[0], "pchar") == 0)
	{
		if (head == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
			free(line);
			free(arguments);
			free_stack(head);
			fclose(file);
			exit(EXIT_FAILURE);
		}

		if (head->n < 0 || head->n > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
			free(line);
			free(arguments);
			free_stack(head);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
}
