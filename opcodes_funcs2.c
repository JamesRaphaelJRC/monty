#include "monty.h"
#include <stdio.h>


int add(stack_t **stack, unsigned int line_no);
int nop(stack_t **stack, unsigned int line_no);
int sub(stack_t **stack, unsigned int line_no);


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


/**
 * nop - Does not do anything.
 * @stack: A pointer to the top element of the stack.
 * @line_no: The current line number.
 *
 * Return: EXIT_SUCCESS on success.
 */
int nop(stack_t **stack, unsigned int line_no)
{
	(void)*stack;
	(void)line_no;

	return (EXIT_SUCCESS);
}


/**
 * sub - Subtracts the top element of the stack from the second top element,
 *		stores the result in the second top element and removes the top
 *		element.
 * @stack: A pointer to the top element.
 * @line_no: The current line number.
 *
 * Return: EXIT_SUCCESS on success.
 */
int sub(stack_t **stack, unsigned int line_no)
{
	int status;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	status = pop(stack, line_no);

	return (status);
}
