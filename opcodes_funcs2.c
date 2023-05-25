#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_no: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_no)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		status = EXIT_FAILURE;
		return;
	}

	res = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_no);/*For top node*/
	(*stack)->n = res;
}


#include "monty.h"

/**
 * nop - This does nothing
 * @stack: stack top
 * @line_no : for nothing
 *
 * Return: NOTHING
 */
void nop(stack_t **stack, unsigned int line_no)
{
	(void) stack;
	(void) line_no;
}
