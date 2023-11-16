#include "monty.h"
char **arguments;
/**
 * main - main function of the monty interpreter
 * @argc: number of arguments given in the command
 * @argv: double array of the commands given
 * Return: retun 0 on success
 */
int main(int argc, char const *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_line(file);

	return (0);
}
/**
 * read_line - open file and read lines
 * @file: pointer to file to be opened
 */
void read_line(FILE *file)
{
	char *line = NULL;
	size_t len;
	unsigned int counter = 0;
	int alert;
	stack_t *head = NULL;

	arguments = malloc(sizeof(char *) * 3);
	if (!arguments)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		counter++;
		if (check_line(line) == 0)
			continue;

		arguments[0] = strtok(line, " \n\t");
		arguments[1] = strtok(NULL, " \n\t");
		arguments[2] = strtok(NULL, " \n\t");

		if (strncmp(arguments[0], "#", 1) == 0)
			continue;

		error_1(line, file, counter, head);
		error_2(line, file, counter, head);
		error_3(line, file, counter, head);

		alert = brain(&head, counter);
		if (alert == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", counter, arguments[0]);
			free_for_all(line, file, head, arguments);
			exit(EXIT_FAILURE);
		}
	}
	free_for_all(line, file, head, arguments);
}
