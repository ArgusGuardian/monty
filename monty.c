#include "monty.h"
char **arguments;

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

	return 0;
}

void read_line(FILE *file)
{
	char *line = NULL;
	size_t len;
	unsigned int counter = 0;
	int alert;
	stack_t *head;

	arguments = malloc(sizeof(char *) * 3);
	if (!arguments)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		counter++;
		arguments[0] = strtok(line, " \n\t");
		arguments[1] = strtok(NULL, " \n\t");
		arguments[2] = strtok(NULL, " \n\t");
		error_handler(line, file, counter, &head);

		alert = brain(&head, counter);
		if (alert == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s", counter, arguments[0]);
			free_for_all(line, file, &head);
			exit(EXIT_FAILURE);
		}
	}
	free_for_all(line, file, &head);
}
