#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int status = 0;


/**
 * main - Entry point for monty interpreter
 * @argc: Number of command line arguments.
 * @argv: A list of command line arguments.
 *
 * Return: The programs exit code.
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	unsigned int line_no = 0;
	stack_t *stack = NULL;

	global.data_struct = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty script_fd\n");
		return (EXIT_FAILURE);
	}

	script_fd = fopen(argv[1], "r");
	if (!script_fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (my_getline(&buffer, &buf_len, script_fd) != -1)
	{
		if (*buffer == '\n')
		{
			line_no++;
			continue;
		}
		str = strtok(buffer, DELIM);
		if (!str || (strcmp(str, "#") == 0))
		{
			line_no++;
			continue;
		}
		global.arg = strtok(NULL,DELIM);
		run_opcode(&stack, str, line_no);
		line_no++;
	}
	free(buffer);
	free_stack(stack);
	fclose(script_fd);
	exit(status);
}
