#include "monty.h"
#include <stdio.h>


int add(stack_t **stack, unsigned int line_no);


/**
 * add - Adds the values of the top two elements of the stack, stores the
 *		result in the second top element of the stack and removess the
 *		top element.
 * @stack: A pointer to the top element.
 * @line_no: The current line number.
 */
int add(stack_t **stack, unsigned int line_no)
{
	int status;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->next->n += (*stack)->next->n;
	status = pop(stack, line_no);

	return (status);
}
