#include "monty.h"
#include <stdio.h>
#include <string.h>

char line[1024];
/**
 * main - Entry point for monty interpreter
 * @ac: Number of command line arguments.
 * @av: A list of command line arguments.
 *
 * Return: The programs exit code.
 */
int main(int ac, char *av[])
{
	stack_t *newstack = NULL, *stack;
	FILE *fd;
	char *word1, *word2;
	unsigned int line_no = 0;

	if (ac != 2)
        {
                fprintf(stdout, "USAGE: monty file\n");
                return (EXIT_FAILURE);
        }

        stack = init_stack(&newstack);
        fd = fopen(av[1], "r");
        if (fd == NULL)
        {
                fprintf(stderr, "USAGE: monty script_fd\n");
                return (EXIT_FAILURE);
        }

        while (fgets(line, sizeof(line), fd) != NULL)
        {
                line_no++;
                word1 = strtok(line, DELIM);
                if (word1 == NULL || word1[0] == '#')
                        continue;
                word2 = strtok(NULL, DELIM);
                parse_to_func(&stack, word1, word2, line_no);
        }
	free(stack);
        fclose(fd);

        return (EXIT_SUCCESS);
}

