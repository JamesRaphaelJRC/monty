#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"


/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 */
void init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;
}


/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the stack to be freed.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}


/**
 * check_file_PATH - Checks if file path and file exists.
 * @path: The path to the file
 */
void check_file_PATH(char *path)
{
	if (access(path, F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
}
