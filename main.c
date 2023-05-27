#include "monty.h"
#include <stdio.h>
#include <string.h>

char *line[1024];
/**
 * main - Entry point for monty interpreter
 * @ac: Number of command line arguments.
 * @av: A list of command line arguments.
 *
 * Return: The programs exit code.
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	FILE *fd;
	char buffer[1024];
	unsigned int line_no = 0;
	int exit_code;

	if (ac != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	check_file_PATH(av[1]);

	init_stack(&stack);
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), fd) != NULL)
	{
		line_no++;
		line[0] = strtok(buffer, DELIM);
		if (line[0] == NULL || line[0][0] == '#')
			continue;
		line[1] = strtok(NULL, DELIM);
		exit_code = parse_to_func(&stack, line_no);
	}

	fclose(fd);
	free_stack(stack);

	return (exit_code);
}
