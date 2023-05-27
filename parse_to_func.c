#include "monty.h"
#include <string.h>
#include <stdlib.h>


/**
 * parse_to_func - Matches the opcode with it's corresponding function.
 * @stack: A pointer to the top of the stack
 * @line_no: The current line number
 *
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE otherwise.
 */
int parse_to_func(stack_t **stack, unsigned int line_no)
{
	int i = 0;
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (op_funcs[i].opcode)
	{
		if (strcmp(op_funcs[i].opcode, line[0]) == 0)
		{
			op_funcs[i].f(stack, line_no);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_no, line[1]);
	return (EXIT_FAILURE);
}
